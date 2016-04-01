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

  // Exported menu link: main-menu_blog:blog.
  $menu_links['main-menu_blog:blog'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'blog',
    'router_path' => 'blog',
    'link_title' => 'Blog',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_blog:blog',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: main-menu_contato:eform/submit/contato.
  $menu_links['main-menu_contato:eform/submit/contato'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'eform/submit/contato',
    'router_path' => 'eform/submit/%',
    'link_title' => 'Contato',
    'options' => array(
      'identifier' => 'main-menu_contato:eform/submit/contato',
    ),
    'module' => 'entityform',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: main-menu_cursos:node/22.
  $menu_links['main-menu_cursos:node/22'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/22',
    'router_path' => 'node/%',
    'link_title' => 'Cursos',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'main-menu_cursos:node/22',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 0,
  );
  // Exported menu link: main-menu_home:<front>.
  $menu_links['main-menu_home:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Home',
    'options' => array(
      'identifier' => 'main-menu_home:<front>',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: main-menu_podcasts:podcast.
  $menu_links['main-menu_podcasts:podcast'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'podcast',
    'router_path' => 'podcast',
    'link_title' => 'Podcasts',
    'options' => array(
      'attributes' => array(
        'title' => 'Ouça os podcasts',
      ),
      'identifier' => 'main-menu_podcasts:podcast',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 0,
  );
  // Exported menu link: main-menu_rss-do-blog:blog/rss.xml.
  $menu_links['main-menu_rss-do-blog:blog/rss.xml'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'blog/rss.xml',
    'router_path' => 'blog/rss.xml',
    'link_title' => 'RSS do Blog',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_rss-do-blog:blog/rss.xml',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'main-menu_rss-geral:rss.xml',
  );
  // Exported menu link: main-menu_rss-dos-podcasts:podcast/rss.xml.
  $menu_links['main-menu_rss-dos-podcasts:podcast/rss.xml'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'podcast/rss.xml',
    'router_path' => 'podcast/rss.xml',
    'link_title' => 'RSS dos Podcasts',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_rss-dos-podcasts:podcast/rss.xml',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'main-menu_rss-geral:rss.xml',
  );
  // Exported menu link: main-menu_rss-dos-vdeos:video/rss.xml.
  $menu_links['main-menu_rss-dos-vdeos:video/rss.xml'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'video/rss.xml',
    'router_path' => 'video/rss.xml',
    'link_title' => 'RSS dos Vídeos',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_rss-dos-vdeos:video/rss.xml',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 1,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'main-menu_rss-geral:rss.xml',
  );
  // Exported menu link: main-menu_rss-geral:rss.xml.
  $menu_links['main-menu_rss-geral:rss.xml'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'rss.xml',
    'router_path' => 'rss.xml',
    'link_title' => 'RSS Geral',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_rss-geral:rss.xml',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -44,
    'customized' => 1,
  );
  // Exported menu link: main-menu_vdeos:video.
  $menu_links['main-menu_vdeos:video'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'video',
    'router_path' => 'video',
    'link_title' => 'Vídeos',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_vdeos:video',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Blog');
  t('Contato');
  t('Cursos');
  t('Home');
  t('Podcasts');
  t('RSS Geral');
  t('RSS do Blog');
  t('RSS dos Podcasts');
  t('RSS dos Vídeos');
  t('Vídeos');

  return $menu_links;
}
