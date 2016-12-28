<?php

/**
 * @file
 * Administrative page code for the smtp module.
 */

/**
 * Administrative settings.
 */
function smtp_admin_settings() {
  if (variable_get('smtp_on', 0)) {
    drupal_set_message(t('SMTP.module is active.'));
  }
  else {
    drupal_set_message(t('SMTP.module is INACTIVE.'));
  }

  $logging = variable_get('smtp_debugging', SMTP_LOGGING_ERRORS);

  $form['onoff'] = array(
    '#type'  => 'fieldset',
    '#title' => t('Install options'),
  );
  $form['onoff']['smtp_on'] = array(
    '#type'          => 'radios',
    '#title'         => t('Turn this module on or off'),
    '#default_value' => variable_get('smtp_on', FALSE),
    '#options'       => array(1 => t('On'), 0 => t('Off')),
    '#description'   => t('To uninstall this module you must turn it off here first.'),
  );
  $form['onoff']['smtp_deliver'] = array(
    '#type'          => 'radios',
    '#title'         => t('Turn on delivery of emails'),
    '#default_value' => variable_get('smtp_deliver', TRUE),
    '#options'       => array(1 => t('On'), 0 => t('Off')),
    '#description'   => t('With this option turned off, email messages will be queued up and processed as normal, but not actually delivered. This option should only be used for testing purposes.'),
  );
  $form['onoff']['smtp_queue'] = array(
    '#type'  => 'checkbox',
    '#title' => t('Send mail by queue'),
    '#default_value' => variable_get('smtp_queue', FALSE),
    '#description'   => t('Mails will be sent by drupal queue api.'),
  );
  $form['onoff']['smtp_queue_fail'] = array(
    '#type'  => 'checkbox',
    '#title' => t('Retry sending mail on error.'),
    '#default_value' => variable_get('smtp_queue_fail', FALSE),
    '#description'   => t('Mails will be added to the queue and sent by drupal queue api.'),
  );

  $form['providers'] = array(
    '#type'  => 'fieldset',
    '#title' => t('Providers'),
  );
  // Create the providers list
  $providers = variable_get('smtp_providers', array());
  if (count($providers) != 0) {
    $rows = array();
    $options = array();
    foreach ($providers as $provider) {
      $rows[] = array($provider['machine_name'], l(t('edit'), 'admin/config/system/smtp/provider/' . $provider['machine_name'] . '/edit', array('class' => 'btn')), l(t('delete'), 'admin/config/system/smtp/provider/' . $provider['machine_name'] . '/delete', array('class' => 'btn')));
      $options[$provider['machine_name']] = $provider['machine_name'];
    }
    $form['providers']['provider_default'] = array(
      '#type'  => 'select',
      '#title' => t('Default provider'),
      '#description'   => t('Mails will be sent by the selected provider when no selection criterias are satisfied.'),
      '#default_value' => variable_get('smtp_default_provider', 'none'),
      '#options' => array_merge(array('none' => 'None'), $options),
    );
    $form['providers']['table'] = array(
      '#theme' => 'table',
      '#header' => array(t('machine name'), '', ),
      '#rows' => $rows,
      '#attributes' => array('class' => array('table-class')),
      '#empty' =>t('Your table is empty'),
    );
  }
  else {
    $form['providers']['message'] = array(
      '#markup' => '<div>' . t('Please add a SMTP provider') . '</div>',
    );
  }

  $form['providers']['new'] = array(
    '#theme' => 'link',
    '#text' => t('Add provider'),
    '#path' => 'admin/config/system/smtp/provider/add',
    '#options' => array(
      'attributes' => array(
        'class' => array(
          'btn'
        ),
      ),
      'html' => FALSE,
    )
  );

  $form['criterias'] = array(
    '#type' => 'fieldset',
    '#title' => t('Selection criterias'),
    '#description' => t('Selection criterias are used to select different providers for different situations.') . '<br>'
                      . t('Criterias will be tested in the order they appear in this table (lowest weight first). The provider selected for the first satisfied criteria will be used.'),
    '#tree' => TRUE,
  );
  $form['criterias']['table'] = array(
    '#theme' => 'smtp_table',
    '#header' => array(t('Provider'), t('Criteria'), array('data' => t('Operations'), 'colspan' => 2), t('Weight')),
    '#attributes' => array(
      'class' => array('btn'),
      'id' => 'smtp-selection-criterias-table',
    ),
    '#empty' => t('No selection criterias defined yet.'),
  );
  $criterias = smtp_list_selection_criterias();
  foreach ($criterias as $cid => $criteria) {
    $form['criterias']['table'][$cid] = array(
      '#attributes' => array(
        'class' => array('draggable'),
      ),
    );
    $form['criterias']['table'][$cid]['provider'] = array(
      '#markup' => check_plain($criteria['provider']),
    );
    $form['criterias']['table'][$cid]['criteria'] = array(
      '#theme' => 'smtp_selection_criteria',
      '#criteria' => $criteria,
    );
    $form['criterias']['table'][$cid]['edit'] = array(
      '#theme' => 'link',
      '#text' => t('edit'),
      '#path' => 'admin/config/system/smtp/criteria/' . $criteria['cid'] . '/edit',
      '#options' => array(
        'attributes' => array(
          'class' => array('btn'),
        ),
        'html' => FALSE,
      ),
    );
    $form['criterias']['table'][$cid]['delete'] = array(
      '#theme' => 'link',
      '#text' => t('delete'),
      '#path' => 'admin/config/system/smtp/criteria/' . $criteria['cid'] . '/delete',
      '#options' => array(
        'attributes' => array(
          'class' => array('btn'),
        ),
        'html' => FALSE,
      ),
    );
    $form['criterias']['table'][$cid]['weight'] = array(
      '#type' => 'textfield',
      '#title' => t('Weight'),
      '#title_display' => 'invisible',
      '#element_validate' => array('element_validate_integer'),
      '#attributes' => array(
        'class' => array('smtp-selection-criteria-weight'),
      ),
      '#size' => 3,
      '#required' => TRUE,
      '#default_value' => $criteria['weight'],
    );
  }
  $form['#attached']['drupal_add_tabledrag'][] = array('smtp-selection-criterias-table', 'order', 'sibling', 'smtp-selection-criteria-weight');
  $form['criterias']['new'] = array(
    '#theme' => 'link',
    '#text' => t('Add selection criteria'),
    '#path' => 'admin/config/system/smtp/criteria/add',
    '#options' => array(
      'attributes' => array(
        'class' => array('btn'),
      ),
      'html' => FALSE,
    ),
  );

  $form['client'] = array(
    '#type'  => 'fieldset',
    '#title' => t('SMTP client settings'),
  );
  $form['client']['smtp_client_hostname'] = array(
    '#type' => 'textfield',
    '#title' => t('Hostname'),
    '#default_value' => variable_get('smtp_client_hostname', ''),
    '#description' => t('The hostname to use in the Message-Id and Received headers, and as the default HELO string. Leave blank for using %server_name.', array('%server_name' => isset($_SERVER['SERVER_NAME']) ? $_SERVER['SERVER_NAME'] : 'localhost.localdomain')),
  );
  $form['client']['smtp_client_helo'] = array(
    '#type' => 'textfield',
    '#title' => t('HELO'),
    '#default_value' => variable_get('smtp_client_helo', ''),
    '#description' => t('The SMTP HELO/EHLO of the message. Defaults to hostname (see above).'),
  );

  $form['email_test'] = array(
    '#type'  => 'fieldset',
    '#title' => t('Send test e-mail'),
  );
  $form['email_test']['smtp_test_address'] = array(
    '#type'          => 'textfield',
    '#title'         => t('E-mail address to send a test e-mail to'),
    '#default_value' => '',
    '#description'   => t('Type in an address to have a test e-mail sent there.'),
  );

  $form['debugging'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Debugging and logging'),
  );

  $logging_options = array(
    SMTP_LOGGING_ALL => t('Log everything'),
    SMTP_LOGGING_ERRORS => t('Errors only'),
    SMTP_LOGGING_NONE => t('No logging'),
  );
  $form['debugging']['smtp_debugging'] = array(
    '#type'          => 'select',
    '#title'         => t('Logging'),
    '#options'       => $logging_options,
    '#default_value' => $logging,
    '#description'   => t('Choose the appropriate log level. "Log everything" will log errors and informational messages when an email is sent. "Errors only" will only create a log entry when sending failed. "No logging" will disable all logging for this module.'),
  );
  $form['email_test']['smtp_reroute_address'] = array(
    '#type'          => 'textfield',
    '#title'         => t('E-mail address to reroute all emails to'),
    '#default_value' => variable_get('smtp_reroute_address', ''),
    '#description'   => t('All emails sent by the site will be rerouted to this email address; use with caution.'),
  );

  $form['debugging']['maillog'] = array(
    '#type' => 'fieldset',
    '#title' => t('Maillog integration'),
  );

  if (!module_exists('maillog')) {
    $form['debugging']['maillog']['#description'] = t('Installing the <a href="@url">Maillog module</a> also allows keeping copies of all emails sent through the site.', array('@url' => 'https://www.drupal.org/project/maillog'));
  }
  else {
    $form['debugging']['maillog']['#description'] = t('The <a href="@url">Maillog module</a> is installed, it can also be used to keep copies of all emails sent through the site.', array('@url' => url('admin/config/development/maillog')));

    $form['debugging']['maillog']['maillog_log'] = array(
      '#type' => 'checkbox',
      '#title' => t("Create table entries in maillog table for each e-mail."),
      '#default_value' => variable_get('maillog_log', TRUE),
    );

    $form['debugging']['maillog']['maillog_devel'] = array(
      '#type' => 'checkbox',
      '#title' => t("Display the e-mails on page using devel module (if enabled)."),
      '#default_value' => variable_get('maillog_devel', TRUE),
      '#disabled' => !module_exists('devel'),
    );
  }

  $form['#submit'][] = 'smtp_admin_settings_form_submit';
  $form = system_settings_form($form);
  $form['#submit'][] = 'smtp_admin_settings_submit_post_system_settings';
  return $form;
}

/**
 * Validation for the administrative settings form.
 */
function smtp_admin_settings_validate($form, &$form_state) {
  if ($form_state['values']['smtp_on'] == 1 && !isset($form_state['values']['provider_default'])) {
    form_set_error(NULL, t('You must add a SMTP provider.'));
    $form_state['values']['smtp_on'] = 0;
  }

  if ($form_state['values']['smtp_on'] == 1 && (!isset($form_state['values']['provider_default']) || $form_state['values']['provider_default'] == 'none')) {
    form_set_error('provider_default', t('You must select a SMTP provider.'));
    $form_state['values']['smtp_on'] = 0;
  }
}  //  End of smtp_admin_settings_validate().

/**
 * Submit handler().
 *
 * @param form
 *   An associative array containing the structure of the form.
 * @param form_state
 *   A keyed array containing the current state of the form.
 */
function smtp_admin_settings_form_submit($form, &$form_state) {
  // Check if SMTP status has been changed.
  if (
    (!variable_get('smtp_on', FALSE) && $form_state['values']['smtp_on']) ||
    (variable_get('smtp_on', FALSE) && !$form_state['values']['smtp_on'])
  ) {
    $mail_modes = variable_get('mail_system', array('default-system' => 'DefaultMailSystem'));

    // Turning on.
    if ($form_state['values']['smtp_on']) {
      variable_set('smtp_previous_mail_system', $mail_modes['default-system']);
      $mail_modes['default-system'] = 'SmtpMailSystem';
    }
    // Turning off.
    else {
      $mail_modes['default-system'] = variable_get('smtp_previous_mail_system', 'DefaultMailSystem');
    }

    variable_set('mail_system', $mail_modes);
  }

  // If there is a provider set, use it.
  if (!empty($form_state['values']['provider_default'])) {
    variable_set('smtp_default_provider', $form_state['values']['provider_default']);
  }

  // If username is set empty, we must set both username/password empty as well.
  if (empty($form_state['values']['smtp_username'])) {
    $form_state['values']['smtp_password'] = '';
  }

  // A little hack. When form is presentend, the password is not shown (Drupal
  // way of doing). So, if user submits the form without changing the password,
  // we must prevent it from being reset.
  elseif (empty($form_state['values']['smtp_password'])) {
    unset($form_state['values']['smtp_password']);
  }

  // Save the test address to send an email after all the settings have been
  // updated.
  $form_state['storage']['smtp']['smtp_test_address'] = $form_state['values']['smtp_test_address'];
  unset($form_state['values']['smtp_test_address']);

  // Saves criterias' weights
  if (!empty($form_state['values']['criterias']['table'])) {
    foreach ($form_state['values']['criterias']['table'] as $cid => $criteria_values) {
      db_update('smtp_selection_criteria')
        ->fields(array('weight' => $criteria_values['weight']))
        ->condition('cid', $cid)
        ->execute();
    }
  }
}

/**
 * Submit handler for the administrative settings form containing all
 * functionality to be run after system_settings_form_submit.
 */
function smtp_admin_settings_submit_post_system_settings($form, &$form_state) {
  // If an address was given, send a test e-mail message.
  $test_address = $form_state['storage']['smtp']['smtp_test_address'];
  if ($test_address != '') {
    $language = language_default();
    $params['subject'] = t('Drupal SMTP test e-mail');
    $params['body'] = array(t('If you receive this message it means your site is capable of using SMTP to send e-mail.'));
    drupal_mail('smtp', 'smtp-test', $test_address, $language, $params);
    drupal_set_message(t('A test e-mail has been sent to @email. You may want to !check for any error messages.', array('@email' => $test_address, '!check' => l(t('check the logs'), 'admin/reports/dblog'))));
  }
}

/**
 * Administrative settings.
 *
 * @param machine_name
 *   The provider identifier inside the provider array
 *
 * @return
 *   An array containing form items to place on the provider edit page.
 */
function smtp_admin_provider_settings($form, $form_state, $machine_name = NULL) {
  $form = array();
  $providers = variable_get('smtp_providers', array());

  if (!empty($machine_name) && empty($providers[$machine_name])) {
    drupal_set_message(t('Invalid provider id.'), 'error');
    return $form;
  }

  $form['server'] = array(
    '#type'  => 'fieldset',
    '#title' => t('SMTP server settingssss'),
  );

  $form['server']['name'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Name'),
    '#default_value' => (!empty($providers[$machine_name]['name']) ? $providers[$machine_name]['name'] : ''),
    //If we are editing a profile, we shouldn't be able to change the machine name
    '#description'   => t("The provider machine name. It should be composed only of alphanumeric characters and underscores and should not start with a underscore."),
  );
  $form['machine_name'] = array(
    '#type' => 'machine_name',
    '#title' => t('Machine Name'),
    '#default_value' => !empty($providers[$machine_name]['machine_name']) ? $providers[$machine_name]['machine_name'] : NULL,
    '#machine_name' => array(
      'exists' => 'smtp_provider_machine_name_exist',
      'source' => array('server', 'name'),
    ),
  );
  $form['server']['smtp_host'] = array(
    '#type'          => 'textfield',
    '#title'         => t('SMTP server'),
    '#default_value' => (!empty($providers[$machine_name]['smtp_host']) ? $providers[$machine_name]['smtp_host'] : ''),
    '#description'   => t('The address of your outgoing SMTP server.'),
  );
  $form['server']['smtp_hostbackup'] = array(
    '#type'          => 'textfield',
    '#title'         => t('SMTP backup server'),
    '#default_value' => (!empty($providers[$machine_name]['smtp_hostbackup']) ? $providers[$machine_name]['smtp_hostbackup'] : ''),
    '#description'   => t('The address of your outgoing SMTP backup server. If the primary server can\'t be found this one will be tried. This is optional.'),
  );
  $form['server']['smtp_port'] = array(
    '#type'          => 'textfield',
    '#title'         => t('SMTP port'),
    '#size'          => 6,
    '#maxlength'     => 6,
    '#default_value' => (!empty($providers[$machine_name]['smtp_port']) ? $providers[$machine_name]['smtp_port'] : '25'),
    '#description'   => t('The default SMTP port is 25, if that is being blocked try 80. Gmail uses 465. See !url for more information on configuring for use with Gmail.', array('!url' => l(t('this page'), 'http://gmail.google.com/support/bin/answer.py?answer=13287'))),
  );

  // Only display the option if openssl is installed.
  if (function_exists('openssl_open')) {
    $encryption_options = array(
      'standard' => t('No'),
      'ssl'      => t('Use SSL'),
      'tls'      => t('Use TLS'),
    );
    $encryption_description = t('This allows connection to a SMTP server that requires SSL encryption such as Gmail.');
  }
  // If openssl is not installed, use normal protocol.
  else {
    $encryption_options = array('standard' => t('No'));
    $encryption_description = t('Your PHP installation does not have SSL enabled. See the !url page on php.net for more information. Gmail requires SSL.', array('!url' => l(t('OpenSSL Functions'), 'http://php.net/openssl')));
  }
  $form['server']['smtp_protocol'] = array(
    '#type'          => 'select',
    '#title'         => t('Use encrypted protocol'),
    '#default_value' => (!empty($providers[$machine_name]['smtp_protocol']) ? $providers[$machine_name]['smtp_protocol'] : 'standard'),
    '#options'       => $encryption_options,
    '#description'   => $encryption_description,
  );

  $form['auth'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('SMTP Authentication'),
    '#description' => t('Leave blank if your SMTP server does not require authentication.'),
  );
  $form['auth']['smtp_username'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Username'),
    '#default_value' => (!empty($providers[$machine_name]['smtp_username']) ? $providers[$machine_name]['smtp_username'] : ''),
    '#description'   => t('SMTP Username.'),
  );
  $form['auth']['smtp_password'] = array(
    '#type'          => 'password',
    '#title'         => t('Password'),
    '#default_value' => (!empty($providers[$machine_name]['smtp_password']) ? $providers[$machine_name]['smtp_password'] : ''),
    '#description'   => t('SMTP password. If you have already entered your password before, you should leave this field blank, unless you want to change the stored password.'),
  );

  $form['email_options'] = array(
    '#type'  => 'fieldset',
    '#title' => t('E-mail options'),
  );
  $form['email_options']['smtp_from'] = array(
    '#type'          => 'textfield',
    '#title'         => t('E-mail from address'),
    '#default_value' => (!empty($providers[$machine_name]['smtp_from']) ? $providers[$machine_name]['smtp_from'] : ''),
    '#description'   => t('The e-mail address that all e-mails will be from.'),
  );
  $form['email_options']['smtp_fromname'] = array(
    '#type'          => 'textfield',
    '#title'         => t('E-mail from name'),
    '#default_value' => (!empty($providers[$machine_name]['smtp_fromname']) ? $providers[$machine_name]['smtp_fromname'] : ''),
    '#description'   => t('The name that all e-mails will be from. If left blank will use the site name of:') . ' ' . variable_get('site_name', 'Drupal powered site'),
  );
  $form['email_options']['smtp_allowhtml'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Allow to send e-mails formatted as Html'),
    '#default_value' => (!empty($providers[$machine_name]['smtp_allowhtml']) ? $providers[$machine_name]['smtp_allowhtml'] : ''),
    '#description'   => t('Checking this box will allow Html formatted e-mails to be sent with the SMTP protocol.'),
  );

  $form['submit'] = array(
     '#type' => 'submit',
     '#value' => t('Submit'),
  );

  return $form;
}

function smtp_provider_machine_name_exist($value, $element, $form_state) {
  $providers = variable_get('smtp_providers', array());

  foreach ($providers as $provider) {
    if ($provider['machine_name'] == $value) {
      return TRUE;
    }
  }

  return FALSE;
}


/**
 * Validation for the administrative settings form.
 *
 * @param form
 *   An associative array containing the structure of the form.
 * @param form_state
 *   A keyed array containing the current state of the form.
 */
function smtp_admin_provider_settings_validate($form, &$form_state) {
  if ($form_state['values']['smtp_port'] == '') {
    form_set_error('smtp_port', t('You must enter a SMTP port number.'));
  }

  if ($form_state['values']['name'] == '') {
    form_set_error('name', t('You must enter a machine name.'));
  }

  if ($form_state['values']['name'] == 'new') {
    form_set_error('name', t("The machine name must not be 'new'."));
  }

  if ($form_state['values']['name'] == 'none') {
    form_set_error('name', t("The machine name must not be 'none'."));
  }

  if ($form_state['values']['smtp_from'] && !valid_email_address($form_state['values']['smtp_from'])) {
    form_set_error('smtp_from', t('The provided from e-mail address is not valid.'));
  }

  // If username is set empty, we must set both username/password empty as well.
  if (empty($form_state['values']['smtp_username'])) {
    $form_state['values']['smtp_password'] = '';
  }

  // A little hack. When form is presentend, the password is not shown (Drupal way of doing).
  // So, if user submits the form without changing the password, we must prevent it from being reset.
  elseif (empty($form_state['values']['smtp_password'])) {
    unset($form_state['values']['smtp_password']);
  }
}

/**
 * Submit handler().
 *
 * @param form
 *   An associative array containing the structure of the form.
 * @param form_state
 *   A keyed array containing the current state of the form.
 */
function smtp_admin_provider_settings_submit($form, &$form_state) {
  $providers = variable_get('smtp_providers', array());
  // Parse the form fields inside a variable
  $provider = array(
    'name' => $form_state['values']['name'],
    'machine_name' => $form_state['values']['machine_name'],
  );
  foreach($form_state['values'] as $key => $value) {
    if (substr($key, 0, 5) == 'smtp_') {
      $provider[$key] = $value;
    }
  }

  // If it exists, remove the previous configuration
  unset($providers[$form_state['values']['machine_name']]);

  // Add it to the providers variable and save
  $providers[$provider['machine_name']] = $provider;
  variable_set('smtp_providers', $providers);

  // Go back to the configuration form
  drupal_goto("admin/config/system/smtp");
}



function smtp_admin_provider_delete($form, $form_state, $machine_name) {
  $providers = variable_get('smtp_providers', array());
  $machine_name = check_plain($machine_name);

  // Check if the provider exists
  if (empty($providers[$machine_name])) {
    drupal_set_message(t("There isn't a provider called :machine_name", array(':machine_name' => $machine_name)), 'error');
    drupal_goto('admin/config/system/smtp');
  }

  // Allows user to select an action if there are selection criterias for this provider
  $criterias = smtp_list_selection_criterias($machine_name);
  if ($criterias) {
    $form['criterias_option'] = array(
      '#type' => 'radios',
      '#title' => t('There are selection criterias using this provider. What would you like to do?'),
      '#options' => array(
        'delete' => t('Delete selection criterias for this provider'),
      ),
      '#default_value' => 'delete',
      '#required' => TRUE,
    );
    $replace_options = array();
    foreach ($providers as $provider) {
      if ($provider['machine_name'] != $machine_name) {
        $replace_options[$provider['machine_name']] = $provider['name'];
      }
    }
    // Allows user to replace provider if there are others configured
    if ($replace_options) {
      $form['criterias_option']['#options']['replace'] = t('Replace selection criterias\' provider by another');
      $default_provider = variable_get('smtp_default_provider', '');
      $form['criterias_replace'] = array(
        '#type' => 'select',
        '#title' => t('Select a provider to be used for replacement'),
        '#options' => $replace_options,
        '#default_value' => ($default_provider != $machine_name) ? $default_provider : NULL,
        '#states' => array(
          'visible' => array(
            ':input[name="criterias_option"]' => array('value' => 'replace'),
          ),
        ),
      );
    }
  }

  $form['machine_name'] = array(
    '#type' => 'value',
    '#value' => $machine_name,
  );
  return confirm_form($form, "Are you sure that you want to delete the provider " . $machine_name  . "?", 'admin/config/system/smtp');
}

function smtp_admin_provider_delete_validate($form, &$form_state) {
  if (!empty($form_state['values']['criterias_option'])) {
    // Must select a provider to replace
    if ($form_state['values']['criterias_option'] == 'replace' && empty($form_state['values']['criterias_replace'])) {
      form_set_error('criterias_replace', t('Select a provider to be used for replacement.'));
    }
  }
}

function smtp_admin_provider_delete_submit($form, $form_state, $form_id) {
  $providers = variable_get('smtp_providers', array());
  $machine_name = $form_state['values']['machine_name'];

  // Delete if from the providers
  if (!empty($providers[$machine_name])) {
    unset($providers[$machine_name]);
  }
  variable_set('smtp_providers', $providers);

  // If the provider is the default one, unset it.
  $default_provider = variable_get('smtp_default_provider', '');
  if ($machine_name == $default_provider) {
    variable_del('smtp_default_provider');
  }

  // Perform the chosen action for selection criterias
  if (!empty($form_state['values']['criterias_option'])) {
    switch ($form_state['values']['criterias_option']) {
      case 'delete':
        db_delete('smtp_selection_criteria')
          ->condition('provider', $machine_name)
          ->execute();
        break;
      case 'replace':
        db_update('smtp_selection_criteria')
          ->fields(array('provider' => $form_state['values']['criterias_replace']))
          ->condition('provider', $machine_name)
          ->execute();
        break;
    }
  }
}

/**
 * Administrative settings.
 *
 * @param form
 *   An associative array containing the structure of the form.
 * @param form_state
 *   A keyed array containing the current state of the form.
 * @param criteria
 *   The selection criteria being edited.
 *
 * @return
 *   An array containing form items to place on the selection criteria edit page.
 */
function smtp_admin_criteria_settings($form, &$form_state, $criteria = NULL) {
  $form_state['storage']['criteria'] = $criteria;

  $providers = variable_get('smtp_providers', array());
  $provider_options = array();
  foreach ($providers as $machine_name => $provider) {
    $provider_options[$machine_name] = $provider['name'];
  }
  $form['provider'] = array(
    '#type' => 'select',
    '#title' => t('Provider'),
    '#description' => t('Provider to be used when this criteria is satisfied.'),
    '#options' => $provider_options,
    '#required' => TRUE,
    '#default_value' => isset($criteria['provider']) ? $criteria['provider'] : NULL,
  );

  $form['message'] = array(
    '#type' => 'fieldset',
    '#title' => t('Message conditions'),
    '#tree' => TRUE,
  );
  $form['message']['module'] = array(
    '#type' => 'select',
    '#title' => t('Module'),
    '#description' => t('Messages sent by the selected module.'),
    '#options' => array('' => t('Any')) + module_list(FALSE, FALSE, TRUE),
    '#default_value' => isset($criteria['message_module']) ? $criteria['message_module'] : '',
  );
  $form['message']['key'] = array(
    '#type' => 'textfield',
    '#title' => t('Key', array(), array('context' => 'identifier')),
    '#description' => t('The key provided to <a href="https://api.drupal.org/api/drupal/includes!mail.inc/function/drupal_mail/7.x" target="_blank">drupal_mail()</a>. Leave it blank for any value.'),
    '#default_value' => isset($criteria['message_key']) ? $criteria['message_key'] : '',
  );
  $language_options = array('' => t('Any'));
  foreach (language_list() as $code => $language) {
    $language_options[$code] = $language->name;
  }
  $form['message']['language'] = array(
    '#type' => 'select',
    '#title' => t('Language'),
    '#description' => t('The message\'s language.'),
    '#options' => $language_options,
    '#default_value' => isset($criteria['message_language']) ? $criteria['message_language'] : '',
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );

  return $form;
}

/**
 * Submit handler.
 *
 * @param form
 *   An associative array containing the structure of the form.
 * @param form_state
 *   A keyed array containing the current state of the form.
 */
function smtp_admin_criteria_settings_submit($form, &$form_state) {
  if (isset($form_state['storage']['criteria']['weight'])) {
    // Do not change the weight of previously created criterias
    $weight = $form_state['storage']['criteria']['weight'];
  }
  else {
    // New criteria receives the highest weight
    $query = db_select('smtp_selection_criteria', 'c');
    $query ->addExpression('MAX(weight) + 1', 'next_weight');
    $result = $query->execute()->fetchAssoc();
    $weight = isset($result['next_weight']) ? $result['next_weight'] : 0;
  }

  // Fields to be updated
  $fields = array(
    'provider' => $form_state['values']['provider'],
    'weight' => $weight,
  );
  foreach ($form_state['values']['message'] as $key => $value) {
    $fields["message_$key"] = $value;
  }

  if (empty($form_state['storage']['criteria'])) {
    // New criteria
    $result = db_insert('smtp_selection_criteria')
      ->fields($fields)
      ->execute();
  }
  else {
    // Update
    $result = db_update('smtp_selection_criteria')
      ->fields($fields)
      ->condition('cid', $form_state['storage']['criteria']['cid'])
      ->execute();
  }

  // Go back to the configuration form
  drupal_goto("admin/config/system/smtp");
}



/**
 * Delete selection criteria.
 *
 * @param form
 *   An associative array containing the structure of the form.
 * @param form_state
 *   A keyed array containing the current state of the form.
 * @param criteria
 *   The selection criteria being edited.
 *
 * @return
 *   An array containing form items to place on the selection criteria deletion page.
 */
function smtp_admin_criteria_delete($form, $form_state, $criteria) {
  $form['cid'] = array(
    '#type' => 'value',
    '#value' => $criteria['cid'],
  );
  return confirm_form($form, 'Are you sure that you want to delete this selection criteria?', 'admin/config/system/smtp');
}

/**
 * Submit handler.
 *
 * @param form
 *   An associative array containing the structure of the form.
 * @param form_state
 *   A keyed array containing the current state of the form.
 */
function smtp_admin_criteria_delete_submit($form, $form_state) {
  $result = db_delete('smtp_selection_criteria')
    ->condition('cid', $form_state['values']['cid'])
    ->execute();

  // Go back to the configuration form
  drupal_goto("admin/config/system/smtp");
}
