<?php
/**
 * @file
 * fs_cursos.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function fs_cursos_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__curso';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
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
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '19',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '16',
        ),
        'redirect' => array(
          'weight' => '18',
        ),
        'xmlsitemap' => array(
          'weight' => '17',
        ),
      ),
      'display' => array(
        'easy_social_1' => array(
          'teaser' => array(
            'weight' => '3',
            'visible' => FALSE,
          ),
          'default' => array(
            'weight' => '6',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__curso'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_curso';
  $strongarm->value = '0';
  $export['language_content_type_curso'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_curso';
  $strongarm->value = array();
  $export['menu_options_curso'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_curso';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_curso'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'metatag_enable_node__curso';
  $strongarm->value = 1;
  $export['metatag_enable_node__curso'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_curso';
  $strongarm->value = array(
    0 => 'promote',
    1 => 'revision',
  );
  $export['node_options_curso'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_curso';
  $strongarm->value = '1';
  $export['node_preview_curso'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_curso';
  $strongarm->value = 0;
  $export['node_submitted_curso'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_curso_pattern';
  $strongarm->value = 'curso/[node:title]';
  $export['pathauto_node_curso_pattern'] = $strongarm;

  return $export;
}
