<?php
/**
 * @file
 * fs_screencast.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function fs_screencast_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:video
  $menu_links['main-menu:video'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'video',
    'router_path' => 'video',
    'link_title' => 'Vídeos',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Vídeos');


  return $menu_links;
}
