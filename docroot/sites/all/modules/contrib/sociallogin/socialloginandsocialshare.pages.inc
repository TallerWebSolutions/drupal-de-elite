<?php
/**
 * @file
 * User page callbacks for the socialloginandsocialshare module.
 */

/**
 * Menu callback Manage socialloginandsocialshare identities for the specified user.
 */
function socialloginandsocialshare_user_identities($account) {
  $user_title = format_username($account);
  drupal_set_title(check_plain($user_title));
  if (user_is_logged_in()) {
    $obj = new LoginRadius();
    $api_handler = trim(variable_get('socialloginandsocialshare_api_handler'));
    $secret = trim(variable_get('socialloginandsocialshare_apisecret'));
    $userprofile = $obj->loginradius_get_data($secret, $api_handler);
    if ($obj->isauthenticated == TRUE AND user_is_logged_in()) {
      $lrdata = socialloginandsocialshare_getuser_data($userprofile);
      $authname_exist = db_select('authmap', 'authname')
                              ->fields('authname')
                              ->condition('authname', $lrdata['id'])
                              ->execute()
                              ->fetchAssoc();
      $result = db_query("SELECT provider FROM {authmap} am INNER JOIN {socialloginandsocialshare_mapusers} sm ON am.aid = sm.aid WHERE module = :module AND uid = :uid", array(':module' => 'socialloginandsocialshare', ':uid' => $account->uid));
      $mapped = '';
      foreach ($result as $identity) {
        if ($identity->provider == $lrdata['provider']) {
          $mapped='yes';
        }
      }
      if (empty($authname_exist) && !$authname_exist ) {
        if ($mapped != 'yes') {
          db_insert('authmap')
            ->fields(array(
            'uid' => $account->uid,
            'authname' => $lrdata['id'],
            'module' => 'socialloginandsocialshare',
          ))
          ->execute();
          if (variable_get('socialloginandsocialshare_update_profile') == 1) {
            if (variable_get('user_pictures') == 1 && !empty($lrdata['thumbnail'])) {
              socialloginandsocialshare_insert_picture($lrdata, $account);
            }
          }
          $aid = db_query('SELECT aid FROM {authmap} WHERE authname = :id', array('id' => $lrdata['id']))->fetchField();
          $check_aid = db_query('SELECT aid FROM {socialloginandsocialshare_mapusers} WHERE aid = :id', array('id' => $aid))->fetchField();
          if (!empty($check_aid)) {
            $query2 = db_delete('socialloginandsocialshare_mapusers')
              ->condition('aid', $aid)
              ->execute();
          }
          db_insert('socialloginandsocialshare_mapusers')
            ->fields(array(
            'aid' => $aid,
            'provider' => $lrdata['provider'],
            'provider_id' => $lrdata['id'],
          ))
          ->execute();
          drupal_set_message(t("Your account sucessfully mapped with this account."));
        }
        else {
          drupal_set_message(t("This social ID is already linked with an account. Kindly unmap the current ID before linking new Social ID."), 'warning');
        }
      }
      else {
        drupal_set_message(t("This account is already linked with an account. try to choose another account."), 'warning');
      }
    }
  }
  $header = array(t('Social Provider'), t('Social Provider ID'), t('Operations'));
  $rows = array();
  $result = db_query("SELECT am.aid, authname, provider, provider_id FROM {authmap} am INNER JOIN {socialloginandsocialshare_mapusers} sm ON am.aid = sm.aid WHERE module = :module AND uid = :uid", array(':module' => 'socialloginandsocialshare', ':uid' => $account->uid));
  foreach ($result as $identity) {
   $provider_name='';
    if (isset($_SESSION['current_social_provider']) && (check_plain($identity->provider_id) == $_SESSION['current_social_provider'])) {
      $provider_name= " [" . t('Currently connected') . "]";
    }
    $rows[] = array('<span' . drupal_attributes(array("class" => "socialloginandsocialshare-mapprovider")) . '>' . '<img src = "' . $GLOBALS['base_url'] . '/' . drupal_get_path('module', 'socialloginandsocialshare') . '/images/' . $identity->provider . '.png">' . $identity->provider . $provider_name . '</span>',
      check_plain($identity->provider_id),
      l(t('Delete'),
      'user/' . $account->uid . '/socialloginandsocialshare/delete/' . $identity->aid),
    );
  }
  $identity_title = variable_get('socialloginandsocialshare_identity_label_string');
  $sociallinks['socialloginandsocialshare_iframe'] = array(
    'title' => t($identity_title) . '<br>' . theme('socialloginandsocialshare_links'),
    'html' => theme('socialloginandsocialshare_links'),
    'attributes' => array('class' => array('socialloginandsocialshare-idlinks')),
  );
  if (variable_get('socialloginandsocialshare_enable') == 1) {
    $build['socialloginandsocialshare_iframe'] = array(
      '#theme' => 'links',
      '#links' => $sociallinks,
      '#attributes' => array('class' => array('socialloginandsocialshare-idlinks')),
    );
  }
  if (sizeof($rows) > 0) {
    $build['socialloginandsocialshare_table'] = array(
      '#theme' => 'table',
      '#header' => $header,
      '#rows' => $rows,
    );
  }
  return $build;
}

/**
 * Menu callback Delete the specified socialloginandsocialshare identity from the system.
 */
function socialloginandsocialshare_user_delete_form($form, $form_state, $account, $aid = 0) {
  $provider = db_query("SELECT provider FROM {authmap} am INNER JOIN {socialloginandsocialshare_mapusers} sm ON am.aid = sm.aid WHERE uid = :uid AND am.aid = :aid AND module = 'socialloginandsocialshare'", array(
    ':uid' => $account->uid,
    ':aid' => $aid,
  ))
  ->fetchField();
  return confirm_form(array(), t('Are you sure you want to delete the Social Login %provider for %user?', array('%provider' => $provider, '%user' => $account->name)), 'user/' . $account->uid . '/socialloginandsocialshare');
}

/**
 * Menu callback Delete form submit for socialloginandsocialshare identity from the system.
 */
function socialloginandsocialshare_user_delete_form_submit($form, &$form_state) {
  $provider = db_query("SELECT provider FROM {authmap} am INNER JOIN {socialloginandsocialshare_mapusers} sm ON am.aid = sm.aid WHERE uid = :uid AND am.aid = :aid AND module = 'socialloginandsocialshare'", array(
    ':uid' => $form_state['build_info']['args'][0]->uid,
    ':aid' => $form_state['build_info']['args'][1],
  ))
  ->fetchField();
  $query = db_delete('authmap')
    ->condition('uid', $form_state['build_info']['args'][0]->uid)
    ->condition('aid', $form_state['build_info']['args'][1])
    ->condition('module', 'socialloginandsocialshare')
    ->execute();
  $query2 = db_delete('socialloginandsocialshare_mapusers')
      ->condition('aid', $form_state['build_info']['args'][1])
      ->execute();
  if ($query && $query2) {
    drupal_set_message(t('Your social login identity for %provider sucessfully deleted.', array('%provider' => $provider)));
  }
  else {
    drupal_set_message(t('We were unable to delete the linked %provider account.', array('%provider' => $provider->provider)), 'error');
  }
  $form_state['redirect'] = 'user/' . $form_state['build_info']['args'][0]->uid . '/socialloginandsocialshare';
}