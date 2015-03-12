<?php
/**
 * @file
 * fs_core.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function fs_core_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:<front>
  $menu_links['main-menu:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
  );
  // Exported menu link: main-menu:blog/rss.xml
  $menu_links['main-menu:blog/rss.xml'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'blog/rss.xml',
    'router_path' => 'blog/rss.xml',
    'link_title' => 'RSS do Blog',
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
    'weight' => -50,
    'parent_path' => 'rss.xml',
  );
  // Exported menu link: main-menu:evento/rss.xml
  $menu_links['main-menu:evento/rss.xml'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'evento/rss.xml',
    'router_path' => 'evento/rss.xml',
    'link_title' => 'RSS dos Eventos',
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
    'parent_path' => 'rss.xml',
  );
  // Exported menu link: main-menu:node/22
  $menu_links['main-menu:node/22'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/22',
    'router_path' => 'node/%',
    'link_title' => 'Cursos',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
  );
  // Exported menu link: main-menu:node/4
  $menu_links['main-menu:node/4'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/4',
    'router_path' => 'node/%',
    'link_title' => 'Contato',
    'options' => array(),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
  );
  // Exported menu link: main-menu:podcast/rss.xml
  $menu_links['main-menu:podcast/rss.xml'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'podcast/rss.xml',
    'router_path' => 'podcast/rss.xml',
    'link_title' => 'RSS dos Podcasts',
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
    'weight' => -49,
    'parent_path' => 'rss.xml',
  );
  // Exported menu link: main-menu:rss.xml
  $menu_links['main-menu:rss.xml'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'rss.xml',
    'router_path' => 'rss.xml',
    'link_title' => 'RSS Geral',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -42,
  );
  // Exported menu link: main-menu:video/rss.xml
  $menu_links['main-menu:video/rss.xml'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'video/rss.xml',
    'router_path' => 'video/rss.xml',
    'link_title' => 'RSS dos Vídeos',
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
    'weight' => -48,
    'parent_path' => 'rss.xml',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Contato');
  t('Cursos');
  t('Home');
  t('RSS Geral');
  t('RSS do Blog');
  t('RSS dos Eventos');
  t('RSS dos Podcasts');
  t('RSS dos Vídeos');


  return $menu_links;
}
