<?php

/**
 * @file
 * socialloginandsocialshare Field mapping.
 */

/**
 * @param $account user account information
 * @param $lrdata contain all user data that got from social network
 * @param $form elements
 * @param $form_state form elements values
 *
 * Create and save profile fields values with social networks values.
 */
function socialloginandsocialshare_field_create_profile_user($account, $lrdata, $form, $form_state) {
  $field_map = variable_get('socialloginandsocialshare_profile_fields', array());
  
  foreach ($field_map as $key => $value) {
    $mapped_value[$key] = array_values($value);
  }
  
  $field_convert_info = socialloginandsocialshare_field_convert_info();
  $instances = field_info_instances('profile2');
  
  foreach (field_info_instances('profile2') as $field_name => $instances) {
    if (!empty($mapped_value[$field_name]) && strlen(implode($mapped_value[$field_name])) != 0) {
      $profile = profile2_load_by_user($account->uid, $field_name);

      if (!$profile) {
        $profile = profile_create(array('type' => $field_name, 'uid' => $account->uid));
      }

      foreach ($instances as $instance => $array) {
        $field = field_info_field($array['field_name']);

        if (isset($field_map[$field_name][$array['field_name']]) && isset($field_convert_info[$field['type']]['callback'])) {
          $callback = $field_convert_info[$field['type']]['callback'];
          $socialloginandsocialshare_property_name = $field_map[$field_name][$array['field_name']];
          $value = $callback($socialloginandsocialshare_property_name, $lrdata, $field);
          $profile->{$array['field_name']}[LANGUAGE_NONE][0]['value'] = $value; // department info got from 3rd party site  
        }

        $form_state = array();
        $form_state['values'] = array();
        $form_state['values']['profile_' . $field_name] = array();
        $form = array();
        $form['#parents'] = array();
        field_attach_submit('profile2', $profile, $form, $form_state); // attach $profile to profile2 submit
        $profile->bundle = $field_name; // main is the profile type which is created in step 3
        profile2_save($profile);
      }
    }
  }
}

/**
 * @param $form_state
 * @param $lrdata contain all user data that got from social network
 *
 * Create and save user fields values with social networks values.
 */
function socialloginandsocialshare_field_create_user(&$form_state, $lrdata) {
  $field_map = variable_get('socialloginandsocialshare_user_fields', array());
  $field_convert_info = socialloginandsocialshare_field_convert_info();
  $instances = field_info_instances('user', 'user');
  
  foreach ($instances as $field_name => $instance) {
    $field = field_info_field($instance['field_name']);

    if (isset($field_map[$field_name]) && isset($field_convert_info[$field['type']]['callback'])) {
      $callback = $field_convert_info[$field['type']]['callback'];
      $socialloginandsocialshare_property_name = $field_map[$field_name];

      if ($value = $callback($socialloginandsocialshare_property_name, $lrdata, $field)) {
        $form_state[$field_name][LANGUAGE_NONE][0] = $value;
      }
    }
  }
}

/**
 * @return array
 *
 * Get callback from specific data type.
 */
function socialloginandsocialshare_field_convert_info() {
  $convert_info = array(
    'text' => array(
      'label' => t('Text'),
      'callback' => 'socialloginandsocialshare_field_convert_text',
    ),
    'text_long' => array(
      'label' => t('Long text'),
      'callback' => 'socialloginandsocialshare_field_convert_text',
    ),
    'list_text' => array(
      'label' => t('List (\'text\')'),
      'callback' => 'socialloginandsocialshare_field_convert_list',
    ),
    'datetime' => array(
      'label' => t('Date'),
      'callback' => 'socialloginandsocialshare_field_convert_date',
    ),
    'date' => array(
      'label' => t('Date'),
      'callback' => 'socialloginandsocialshare_field_convert_date',
    ),
    'datestamp' => array(
      'label' => t('Date'),
      'callback' => 'socialloginandsocialshare_field_convert_date',
    ),
  );
  drupal_alter('socialloginandsocialshare_field_convert_info', $convert_info);
  return $convert_info;
}

/**
 * @param $socialloginandsocialshare_property_name
 * @param $lrdata
 * @param $field
 * @return array|null
 *
 * Get the value of text and long text text values from LoginRadius data.
 */
function socialloginandsocialshare_field_convert_text($socialloginandsocialshare_property_name, $lrdata, $field) {
  $value = NULL;
  
  if (isset($lrdata[$socialloginandsocialshare_property_name])) {
    if (is_string($lrdata[$socialloginandsocialshare_property_name])) {
      $value = $lrdata[$socialloginandsocialshare_property_name];
    }
    elseif (is_object($lrdata[$socialloginandsocialshare_property_name])) {
      $object = $lrdata[$socialloginandsocialshare_property_name];

      if (isset($object->name)) {
        $value = $object->name;
      }
    }
  }
  
  return $value ? array('value' => $value) : NULL;
}

/**
 * @param $socialloginandsocialshare_property_name
 * @param $lrdata
 * @param $field
 * @return array|null
 *
 * GEt list values from LoginRadius Data.
 */
function socialloginandsocialshare_field_convert_list($socialloginandsocialshare_property_name, $lrdata, $field) {
  if (!isset($lrdata[$socialloginandsocialshare_property_name]) || !is_string($lrdata[$socialloginandsocialshare_property_name])) {
    return;
  }
  
  $options = list_allowed_values($field);
  $best_match = 0.0;
  $best_option = NULL;
  $match_sl = strtolower($lrdata[$socialloginandsocialshare_property_name]);
  
  foreach ($options as $key => $option) {
    $match_option = strtolower(trim($option));
    $this_match = 0;
    similar_text($match_option, $match_sl, $this_match);

    if ($this_match > $best_match) {
      $best_match = $this_match;
      $best_option = trim($option);
      $best_key = $key;
    }
  }
  
  return isset($best_key) ? array('value' => $best_key) : NULL;
}

/**
 * @param $socialloginandsocialshare_property_name
 * @param $lrdata
 * @param $field
 * @return array|null
 *
 * Get date.
 */
function socialloginandsocialshare_field_convert_date($socialloginandsocialshare_property_name, $lrdata, $field) {
  $value = NULL;
  $sldate = explode('/', $lrdata[$socialloginandsocialshare_property_name]);
  
  if (count($sldate) == 3) {
    $date = new DateObject($lrdata[$socialloginandsocialshare_property_name]);

    if (date_is_date($date)) {
      $format = $field['type'] == 'datestamp' ? DATE_FORMAT_UNIX : DATE_FORMAT_ISO;
      $value = array(
        'value' => $date->format($format, TRUE),
        'date_type' => $field['type'],
      );
    }
  }
  
  return $value;
}

/**
 * @param bool $include_common
 * @return array
 *
 *  Return a all list of social user properties.
 */
function socialloginandsocialshare_user_properties() {
  $common = array(
    'id' => array(
      'label' => t('Provider ID'),
    ),
    'provider' => array(
      'label' => t('Social Provider'),
      'field_types' => array('text'),
    ),
    'fullname' => array(
      'label' => t('Full name'),
      'field_types' => array('text'),
    ),
    'fname' => array(
      'label' => t('First name'),
      'field_types' => array('text'),
    ),
    'lname' => array(
      'label' => t('Last name'),
      'field_types' => array('text'),
    ),
    'email' => array(
      'label' => t('E-mail'),
      'field_types' => array('text'),
    ),
    'gender' => array(
      'label' => t('Gender'),
      'field_types' => array('text', 'list_text'),
    ),
    'dob' => array(
      'label' => t('Birthday'),
      'field_types' => array('text', 'date', 'datetime', 'datestamp'),
    ),
    'aboutme' => array(
      'label' => t('About me (a short bio)'),
      'field_types' => array('text', 'text_long'),
    ),
    'address' => array(
      'label' => t('Location'),
      'field_types' => array('text'),
    ),
    'company' => array(
      'label' => t('Work history'),
      'field_types' => array('text'),
    ),
    'website' => array(
      'label' => t('Profile url'),
      'field_types' => array('text'),
    ),
    'nickname' => array(
      'label' => t('Nick name'),
      'field_types' => array('text'),
    ),
    'state' => array(
      'label' => t('State'),
      'field_types' => array('text'),
    ),
    'city' => array(
      'label' => t('City'),
      'field_types' => array('text'),
    ),
    'country' => array(
      'label' => t('Country'),
      'field_types' => array('text'),
    ),
    'id' => array(
      'label' => t('Social ID'),
      'field_types' => array('text'),
    ),
    'positions' => array(
      'label' => t('Positions'),
      'field_types' => array('text'),
    ),
    'educations' => array(
      'label' => t('Educations'),
      'field_types' => array('text'),
    ),
    'favoritethings' => array(
      'label' => t('Favorite Things'),
      'field_types' => array('text'),
    ),
  );
  drupal_alter('socialloginandsocialshare_user_properties', $common);
  ksort($common);
  return $common;
}