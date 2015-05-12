<?php
/**
 * @file
 * fs_screencast.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function fs_screencast_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|screencast|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'screencast';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'disqus_comments' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|screencast|full'] = $ds_fieldsetting;

  return $export;
}
