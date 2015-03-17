<?php

/**
 * @file
 * Helper file that conatin functions that rquired by social login module file
 */

/**
 * Respond to altering user login/register form.
 *
 * @param array $form
 *   Nested array of form elements that comprise the form.
 * @param array $form_state
 *   A keyed array containing the current state of the form.
 */
function socialloginandsocialshare_user_login_form_alter(&$form) {
  $api_key = trim(variable_get('socialloginandsocialshare_apikey'));
  $secret = trim(variable_get('socialloginandsocialshare_apisecret'));
  $iconpos = variable_get('socialloginandsocialshare_showicon_location', 0) ? 102 : -102;

  if (!empty($api_key) && !empty($secret) && (!preg_match('/^\{?[A-Z0-9]{8}-[A-Z0-9]{4}-[A-Z0-9]{4}-[A-Z0-9]{4}-[A-Z0-9]{12}\}?$/i', $api_key) || !preg_match('/^\{?[A-Z0-9]{8}-[A-Z0-9]{4}-[A-Z0-9]{4}-[A-Z0-9]{4}-[A-Z0-9]{12}\}?$/i', $secret))) {
    $form['socialloginandsocialshare_links'] = array(
      '#type' => 'item',
      '#title' => t('<div class="interface_error">Your LoginRadius API key or secret is not valid, please correct it or contact LoginRadius support at <a href="@this" target="_blank">www.LoginRadius.com</a></div>', array('@this' => 'http://www.Loginradius.com/')),
      '#attributes' => array('class' => array('socialloginandsocialshare-links')),
      '#weight' => $iconpos,
    );
  }
  elseif (!empty($api_key) && !empty($secret)) {
    //  $label_string = variable_get('socialloginandsocialshare_label_string');
    $form['socialloginandsocialshare_links'] = array(
      '#type' => 'item',
      '#title' => variable_get('socialloginandsocialshare_label_string'),
      '#markup' => theme('socialloginandsocialshare_links'),
      '#attributes' => array('class' => array('socialloginandsocialshare-links')),
      '#weight' => $iconpos,
    );
  }
}

/**
 * @param $vars
 *
 * Set all variables that required to show social login/linking interface.
 */
function socialloginandsocialshare_options(&$vars) {
  $vars['api_key'] = trim(variable_get('socialloginandsocialshare_apikey'));
  $vars['loc'] = get_callback_url();
  $vars['interfaceiconsize'] = variable_get('socialloginandsocialshare_interface_size') == 0 ? "small" : "";
  $interfacebackgroundcolor = variable_get('socialloginandsocialshare_interface_bgcolor');
  $vars['interfacebackgroundcolor'] = !empty($interfacebackgroundcolor) ? trim($interfacebackgroundcolor) : "";
  $interfacerow = variable_get('socialloginandsocialshare_interface_columns');
  $vars['interfacerow'] = !empty($interfacerow) && is_numeric($interfacerow) ? trim($interfacerow) : 0;
}

/**
 * @param $key
 * @param null $language
 * @param array $variables
 * @return mixed|null|string
 *
 * Email Content when new user registers.
 */
function socialloginandsocialshare_mail_text($key, $language = NULL, $variables = array()) {
  $langcode = isset($language) ? $language->language : NULL;

  // No override, return default string.
  switch ($key) {
    case 'newuser_subject':
      $text = t('Thank you for registering at [site:name]', array(), array('langcode' => $langcode));
      break;
    case 'newuser_body':
      $email_content_unformat = socialloginandsocialshare_email_content_text();
      $email_content = t($email_content_unformat, array('@password' => t($variables['pass'])));
      $text = t($email_content, array(), array('langcode' => $langcode));
      break;
  }

  $text = token_replace($text, $variables, array('language' => $language, 'callback' => 'user_mail_tokens'));
  return $text;
}

/**
 * Get Current Page Url after login/register
 */
function get_callback_url() {
  $request_uri = request_uri();

  if (strpos($request_uri, 'user/register')) {
    variable_set('sociallogin_user_register_redirect', 1);
  }
  elseif (strpos($request_uri, 'socialloginandsocialshare/token_handler') == FALSE) {
    variable_del('sociallogin_user_register_redirect');
  }

  $destination = drupal_get_destination();
  $destination_value = $destination['destination'];

  if (strpos($destination_value, 'ajax') !== FALSE) {
    if (isset($_SESSION['redirect_url'])) {
      return $_SESSION['redirect_url'];
    }
    else {
      $destination_value = 'user';
    }
  }

  $query[] = array('destination' => $destination_value);
  $url = url('socialloginandsocialshare/token_handler', array('query' => $query, 'absolute' => TRUE));

  if (module_exists('ajax_register') || module_exists('modal_forms')) {
    $_SESSION['redirect_url'] = $url;
  }

  return $url;
}

/**
 * @param $lrdata contain user data that got from social networks.
 * @param $account
 *
 * Function that insert social user picture.
 */
function socialloginandsocialshare_insert_picture($lrdata, $account) {

  if ($account->uid) {
    $uri = (!empty($account->picture->uri) ? $account->picture->uri : '');
    $fid = (!empty($account->picture->fid) ? $account->picture->fid : 0);

    if (empty($uri)) {
      $fid = (!empty($account->picture) ? $account->picture : 0);
      $picture = file_load($fid);
      $uri = (!empty($picture->uri) ? $picture->uri : '');
    }

    if (file_exists($uri) && !empty($uri)) {
      $picture = $account->picture;
      file_delete(file_load($fid), TRUE);
    }

    $image_directory = file_default_scheme() . '://' . variable_get('user_picture_path', 'pictures');

    if (file_prepare_directory($image_directory, FILE_CREATE_DIRECTORY)) {
      $image_result = drupal_http_request($lrdata['thumbnail']);
      $picture_path = file_stream_wrapper_uri_normalize($image_directory . '/picture-' . $account->uid . '-' . REQUEST_TIME . '.jpg');

      if (!empty($image_result->data)) {
        $picture_file = file_save_data($image_result->data, $picture_path, FILE_EXISTS_REPLACE);
        $max_dimensions = variable_get('user_picture_dimensions', '85x85');
        file_validate_image_resolution($picture_file, $max_dimensions);
        $picture_file->uid = $account->uid;
        $picture_file_data = file_save($picture_file);
        file_usage_add($picture_file_data, 'user', 'user', $account->uid);
        db_update('users')
            ->fields(array(
              'picture' => $picture_file_data->fid,
            ))
            ->condition('uid', $account->uid)
            ->execute();
        $account->picture = $picture_file_data->fid;
      }
    }
  }
}

/**
 * @param $str string
 * @return mixed|string
 *
 * Function that remove unescaped char from string.
 */
function socialloginandsocialshare_remove_unescaped_char($str) {
  $in_str = str_replace(array('<', '>', '&', '{', '}', '*', '/', '(', '[', ']', '!', ')', '&', '*', '#', '$', '%', '^', '|', '?', '+', '=', '"', ','), array(''), $str);
  $cur_encoding = mb_detect_encoding($in_str);

  if ($cur_encoding == "UTF-8" && mb_check_encoding($in_str, "UTF-8")) {
    return $in_str;
  }
  else {
    return utf8_encode($in_str);
  }
}

/**
 * @return null|string
 *
 * Welcome email content.
 */
function socialloginandsocialshare_email_content_text() {
  $output = variable_get('socialloginandsocialshare_email_content', FALSE);

  if (!$output && $output !== '') {
    $output = '';
    $output .= '[user:name],

Your account at [site:name] has been created.

Please use following credentials to log into your account:

Website : [site:login-url]
User name : [user:name]
Password :  @password

--  [site:name]';
  }

  return $output;
}

/**
 * @param $form
 * @param $lrdata
 * @return mixed
 *
 * Show profile field to register form.
 */
function socialloginandsocialshare_show_profile_field_to_register_form($form, $lrdata) {
  module_load_include('inc', 'socialloginandsocialshare', 'socialloginandsocialshare.field');
  $field_map = variable_get('socialloginandsocialshare_user_fields', array());
  $field_convert_info = socialloginandsocialshare_field_convert_info();
  $instances = field_info_instances('user', 'user');

  foreach ($instances as $field_name => $instance) {
    $field = field_info_field($instance['field_name']);

    if (isset($field_map[$field_name]) && isset($field_convert_info[$field['type']]['callback'])) {
      $callback = $field_convert_info[$field['type']]['callback'];
      $socialloginandsocialshare_property_name = $field_map[$field_name];

      if ($value = $callback($socialloginandsocialshare_property_name, $lrdata, $field, $instance)) {
        $form[$field_name][LANGUAGE_NONE][0]['value']['#default_value'] = $value;
      }
    }
  }

  if (module_exists('profile2')) {
    $field_map = variable_get('socialloginandsocialshare_profile_fields', array());
    $field_convert_info = socialloginandsocialshare_field_convert_info();

    foreach (field_info_instances('profile2') as $field_name => $instances) {
      foreach ($instances as $instance => $array) {
        $field = field_info_field($array['field_name']);

        if (isset($field_map[$field_name][$array['field_name']]) && isset($field_convert_info[$field['type']]['callback'])) {
          $callback = $field_convert_info[$field['type']]['callback'];
          $socialloginandsocialshare_property_name = $field_map[$field_name][$array['field_name']];

          if ($value = $callback($socialloginandsocialshare_property_name, $lrdata, $field, $array)) {
            $form['profile_' . $field_name][$array['field_name']][LANGUAGE_NONE][0]['value']['#default_value'] = $value;
          }
        }
      }
    }
  }

  return $form;
}

/**
 * @param $gender
 * @return string
 *
 * Get gender.
 */
function socialloginandsocialshare_get_gender($gender) {
  if ($gender == 'M') {
    return 'Male';
  }
  elseif ($gender == 'F') {
    return 'Female';
  }
}

/**
 * @param $email
 * @param $provider_id
 * @param $provider
 * @return string
 *
 * Get email address by provider id when email is empty.
 */
function socialloginandsocialshare_get_email_by_provider_id($email, $provider_id, $provider) {
  switch ($provider) {
    case 'twitter':
      $email = $provider_id . '@' . $provider . '.com';
      break;
    default:
      $email_id = drupal_substr($provider_id, 7);
      $email_id2 = str_replace("/", "_", $email_id);
      $email = str_replace(".", "_", $email_id2) . '@' . $provider . '.com';
      break;
  }

  return $email;
}

/**
 * @param $lrdata
 *
 * Forcefully submit data through registration form
 */
function socialloginandsocialshare_enable_force_registration($lrdata) {
  if (variable_get('socialloginandsocialshare_force_registration') == 0) {
    $_SESSION['social_lrdata'] = $lrdata;
    unset($_GET['destination']);
    drupal_goto('user/register');
  }
}

/**
 * @param $userprofile
 *
 * Show error message when user profile is not retrieved or error message is showing.
 */
function socialloginandsocialshare_show_error_message($userprofile) {
  if (variable_get('socialloginandsocialshare_debug_mode') == 1) {
    if (isset($userprofile->description) && !empty($userprofile->description)) {
      drupal_set_message(t($userprofile->description), 'error');
    }
    else {
      drupal_set_message(t('UserProfile is not retrieved'), 'error');
    }
  }
  else {
    drupal_set_message(t('An error occurred during the processing of your request. Please try again in a few minutes or contact the site admin.'), 'error');
  }

  drupal_goto();
}

/**
 * @param $aid
 * @param $provider
 * @param $id
 *
 * map the social network data into mapping table.
 */
function socialloginandsocialshare_insert_into_mapping_table($aid, $provider, $id) {
  $check_aid = db_query('SELECT aid FROM {socialloginandsocialshare_mapusers} WHERE aid = :id', array('id' => $aid))->fetchField();

  if (!empty($check_aid)) {
    db_delete('socialloginandsocialshare_mapusers')
        ->condition('aid', $aid)
        ->execute();
  }

  db_insert('socialloginandsocialshare_mapusers')
      ->fields(array(
        'aid' => $aid,
        'provider' => $provider,
        'provider_id' => $id,
      ))
      ->execute();
}

/**
 * @param $popup_params
 * @return array
 *
 * Get the form element to show emial popup.
 */
function socialloginandsocialshare_get_form_element_to_show_email_popup($popup_params) {
  return array(
    '#type' => 'item',
    '#title' => '',
    '#markup' => theme('socialloginandsocialshare_popup', array('popup_params' => $popup_params)),
    '#weight' => 20,
  );
}

/**
 * @param $id social network id
 * @return string
 *
 * Get facebook social picture.
 */
function socialloginandsocialshare_get_facebook_social_picture($id) {
  return "http://graph.facebook.com/" . $id . "/picture?type=square";
}
