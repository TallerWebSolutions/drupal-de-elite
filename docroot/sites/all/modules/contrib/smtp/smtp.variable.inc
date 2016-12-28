<?php
/**
 * @file
 * Custom integration with the Variable module.
 */

/**
 * Implements hook_variable_info().
 *
 * Allows for the SMTP from name to be translated if/when the Variable module
 * is enabled.
 *
 * @link http://api.drupalhelp.net/api/variable/variable.api.php/function/hook_variable_info/7
 *
 * @param array $options
 */
function smtp_variable_info($options) {
  // Create a new variable for each provider.
  $variable = array();
  foreach (variable_get('smtp_providers', array()) as $provider_name => $value) {
    $variable['smtp_fromname_' . $provider_name] = array (
      'title' => t('Email from name for provider :provider_name (SMTP module)', array(':provider_name' => $provider_name)),
      'type' => 'string',
      'group' => 'smtp',
    );
  }

  return $variable;
}
