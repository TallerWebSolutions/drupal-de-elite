<?php
/**
 * @file
 * responsive_menus_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function responsive_menus_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
