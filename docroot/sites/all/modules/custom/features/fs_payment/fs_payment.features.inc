<?php
/**
 * @file
 * fs_payment.features.inc
 */

/**
 * Implements hook_commerce_product_default_types().
 */
function fs_payment_commerce_product_default_types() {
  $items = array(
    'curso' => array(
      'type' => 'curso',
      'name' => 'Curso',
      'description' => 'Cursos Drupal de elite',
      'help' => '',
      'revision' => '1',
    ),
  );
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function fs_payment_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function fs_payment_node_info() {
  $items = array(
    'product_display_reference' => array(
      'name' => t('Product Display Reference'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
