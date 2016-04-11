<?php
/**
 * @file
 * fs_eventos.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function fs_eventos_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__evento';
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
        'metatags' => array(
          'weight' => '10',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '9',
        ),
        'redirect' => array(
          'weight' => '8',
        ),
        'xmlsitemap' => array(
          'weight' => '7',
        ),
        'flag' => array(
          'weight' => '12',
        ),
      ),
      'display' => array(
        'easy_social_1' => array(
          'teaser' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
          'rss' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
        ),
        'disqus' => array(
          'default' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
          'teaser' => array(
            'weight' => '6',
            'visible' => FALSE,
          ),
          'rss' => array(
            'weight' => '5',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__evento'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_evento';
  $strongarm->value = '0';
  $export['language_content_type_evento'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_evento';
  $strongarm->value = array();
  $export['menu_options_evento'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_evento';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_evento'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'metatag_enable_node__evento';
  $strongarm->value = 1;
  $export['metatag_enable_node__evento'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_evento';
  $strongarm->value = array(
    0 => 'promote',
    1 => 'revision',
  );
  $export['node_options_evento'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_evento';
  $strongarm->value = '1';
  $export['node_preview_evento'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_evento';
  $strongarm->value = 0;
  $export['node_submitted_evento'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_evento_pattern';
  $strongarm->value = 'evento/[node:title]';
  $export['pathauto_node_evento_pattern'] = $strongarm;

  return $export;
}
