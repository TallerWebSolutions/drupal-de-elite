<?php
/**
 * @file
 * fs_podcast.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function fs_podcast_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|podcast|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'podcast';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'disqus_comments' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|podcast|full'] = $ds_fieldsetting;

  return $export;
}
