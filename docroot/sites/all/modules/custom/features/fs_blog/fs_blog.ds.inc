<?php
/**
 * @file
 * fs_blog.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function fs_blog_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'teaser';
  $ds_view_mode->label = 'Teaser';
  $ds_view_mode->entities = array(
    'commerce_customer_profile' => 'commerce_customer_profile',
    'commerce_line_item' => 'commerce_line_item',
    'commerce_order' => 'commerce_order',
    'commerce_product' => 'commerce_product',
    'metatags_path_based' => 'metatags_path_based',
    'node' => 'node',
    'file' => 'file',
    'taxonomy_term' => 'taxonomy_term',
    'user' => 'user',
    'rules_config' => 'rules_config',
  );
  $export['teaser'] = $ds_view_mode;

  return $export;
}
