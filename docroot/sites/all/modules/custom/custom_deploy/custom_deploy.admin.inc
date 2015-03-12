<?php

/**
 * @file
 * Administration page callbacks for the custom_deploy module.
 */

/**
 * Form builder. Set custom_deploy preferences.
 *
 * @ingroup forms
 * @see system_settings_form().
 */

function custom_deploy_admin_settings($form, &$form_state) {
  // Define what functions will run at each
  // time in the custom_deploy

  $values = db_select('custom_deploy', 'c')
    ->fields('c')
    ->orderBy('cdid', 'DESC')
    ->execute()
    ->fetchAssoc();

  $custom_deploy_options = array(
    '1' => t('Put site on maintenence mode during deploy'),
    '2' => t('GIT pull to get developers update code'),
    '3' => t('Revert all features'),
    '4' => t('Clear all caches after deploy'),
    '5' => t('Run cron after deploy'),
  );

  $form['custom_deploy_set_preferences'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Choice the functions to run for each Custom Deploy submit'),
    '#options' => $custom_deploy_options,
    '#default_value' => $values['actions'] ? unserialize($values['actions']) : array(),
    '#description' => t('This options run all time when the Custom Deploy option is submited.'),
    '#required' => TRUE,
  );

  $form['custom_deploy_user_information'] = array(
    '#type' => 'fieldset',
    '#title' => t('User information'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#description' => t('We use a server connection to run <strong>GIT</strong> and <strong>drush</strong> commands. So let me know about username and pass to connect in this server.'),
  );

  $form['custom_deploy_user_information']['username'] = array(
    '#type' => 'textfield',
    '#title' => t('Username'),
    '#default_value' => $values['username'],
    '#required' => TRUE,
  );

  $form['custom_deploy_user_information']['password'] = array(
    '#type' => 'password',
    '#title' => t('Password'),
    '#default_value' => $values['password'],
    '#required' => TRUE,
  );

  $form['custom_deploy_send_email'] = array(
    '#type' => 'fieldset',
    '#title' => t('Send email confirmation message'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['custom_deploy_send_email']['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Send email'),
    '#default_value' => $values['email_address'],
    '#description' => t('Input a email address to send a custom message after deploy. Leave blank to no send message'),
  );

  $form['custom_deploy_send_email']['message'] = array(
    '#type' => 'textarea',
    '#title' => t('Message'),
    '#default_value' => $values['email_message'],
    '#description' => t('Input a message to send after deploy.'),
  );

  $form['custom_deploy_submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  $form['#submit'][] = 'custom_deploy_admin_settings_submit';
  return $form;
}

/**
 * Process custom_deploy preferences form
 */

function custom_deploy_admin_settings_submit($form, &$form_state) {
  // Get values from current choices and insert on database
  $actions = array_filter($form_state['values']['custom_deploy_set_preferences']);
  $record = array(
    'actions' => serialize($actions),
    'username' => $form_state['values']['username'],
    'password' => $form_state['values']['password'],
    'email_address' => $form_state['values']['email'],
    'email_message' => $form_state['values']['message'],
  );

  drupal_write_record('custom_deploy', $record);
}