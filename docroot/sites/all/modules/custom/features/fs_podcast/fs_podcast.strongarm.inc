<?php
/**
 * @file
 * fs_podcast.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function fs_podcast_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__podcast';
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
            'weight' => '3',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'rss' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
        ),
        'disqus' => array(
          'default' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '4',
            'visible' => FALSE,
          ),
          'rss' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__podcast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_podcast';
  $strongarm->value = '0';
  $export['language_content_type_podcast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_podcast';
  $strongarm->value = array();
  $export['menu_options_podcast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_podcast';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_podcast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'metatag_enable_node__podcast';
  $strongarm->value = 1;
  $export['metatag_enable_node__podcast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_podcast';
  $strongarm->value = array(
    0 => 'promote',
    1 => 'revision',
  );
  $export['node_options_podcast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_podcast';
  $strongarm->value = '1';
  $export['node_preview_podcast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_podcast';
  $strongarm->value = 0;
  $export['node_submitted_podcast'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_podcast_pattern';
  $strongarm->value = 'podcast/[node:title]';
  $export['pathauto_node_podcast_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_tags_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_tags_pattern'] = $strongarm;

  return $export;
}
