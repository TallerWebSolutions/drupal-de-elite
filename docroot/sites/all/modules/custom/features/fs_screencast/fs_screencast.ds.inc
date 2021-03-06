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

/**
 * Implements hook_ds_layout_settings_info().
 */
function fs_screencast_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|screencast|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'screencast';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_video',
        1 => 'field_description',
        2 => 'field_tags',
        3 => 'easy_social_1',
        4 => 'disqus_comments',
      ),
    ),
    'fields' => array(
      'field_video' => 'ds_content',
      'field_description' => 'ds_content',
      'field_tags' => 'ds_content',
      'easy_social_1' => 'ds_content',
      'disqus_comments' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|screencast|full'] = $ds_layout;

  return $export;
}
