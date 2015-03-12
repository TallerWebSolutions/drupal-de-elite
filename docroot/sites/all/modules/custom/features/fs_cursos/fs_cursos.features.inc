<?php
/**
 * @file
 * fs_cursos.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function fs_cursos_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function fs_cursos_views_api() {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function fs_cursos_node_info() {
  $items = array(
    'curso' => array(
      'name' => t('Curso'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Título'),
      'help' => '',
    ),
  );
  return $items;
}
