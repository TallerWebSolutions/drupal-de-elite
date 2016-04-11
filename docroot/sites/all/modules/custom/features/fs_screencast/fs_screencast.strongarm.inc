<?php
/**
 * @file
 * fs_screencast.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function fs_screencast_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__screencast';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => TRUE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'flag' => array(
          'weight' => '5',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '5',
        ),
        'metatags' => array(
          'weight' => '8',
        ),
        'redirect' => array(
          'weight' => '7',
        ),
        'xmlsitemap' => array(
          'weight' => '6',
        ),
      ),
      'display' => array(
        'easy_social_1' => array(
          'default' => array(
            'weight' => '2',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'rss' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
        ),
        'disqus' => array(
          'teaser' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'rss' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
          'default' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__screencast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_screencast';
  $strongarm->value = '0';
  $export['language_content_type_screencast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_screencast';
  $strongarm->value = array();
  $export['menu_options_screencast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_screencast';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_screencast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'metatag_enable_node__screencast';
  $strongarm->value = 1;
  $export['metatag_enable_node__screencast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_screencast';
  $strongarm->value = array(
    0 => 'promote',
    1 => 'revision',
  );
  $export['node_options_screencast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_screencast';
  $strongarm->value = '1';
  $export['node_preview_screencast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_screencast';
  $strongarm->value = 0;
  $export['node_submitted_screencast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_file_video_pattern';
  $strongarm->value = '';
  $export['pathauto_file_video_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_screencast_pattern';
  $strongarm->value = 'video/[node:title]';
  $export['pathauto_node_screencast_pattern'] = $strongarm;

  return $export;
}
