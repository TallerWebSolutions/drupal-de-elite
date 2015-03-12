<?php
/**
 * @file
 * fs_core.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function fs_core_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
  if ($module == "file_entity" && $api == "file_type") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function fs_core_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function fs_core_flag_default_flags() {
  $flags = array();
  // Exported flag: "Destaques".
  $flags['hightlight'] = array(
    'content_type' => 'node',
    'title' => 'Destaques',
    'global' => 1,
    'types' => array(
      0 => 'evento',
      1 => 'podcast',
      2 => 'blog',
      3 => 'screencast',
    ),
    'flag_short' => 'Promover a destaque',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Remover do destaque',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => 3,
      ),
      'unflag' => array(
        0 => 3,
      ),
    ),
    'weight' => 0,
    'show_on_form' => 1,
    'access_author' => '',
    'show_on_page' => 1,
    'show_on_teaser' => 1,
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'fs_core',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  // Exported flag: "Subscribe".
  $flags['subscribe'] = array(
    'content_type' => 'node',
    'title' => 'Subscribe',
    'global' => 0,
    'types' => array(
      0 => 'curso',
      1 => 'evento',
    ),
    'flag_short' => 'Inscrever',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Desinscrever',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'normal',
    'roles' => array(
      'flag' => array(
        0 => 2,
      ),
      'unflag' => array(
        0 => 2,
      ),
    ),
    'weight' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_on_page' => 1,
    'show_on_teaser' => 1,
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'fs_core',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  return $flags;

}

/**
 * Implements hook_image_default_styles().
 */
function fs_core_image_default_styles() {
  $styles = array();

  // Exported image style: body_post_660.
  $styles['body_post_660'] = array(
    'name' => 'body_post_660',
    'label' => 'body_post_660',
    'effects' => array(
      1 => array(
        'label' => 'Escala',
        'help' => 'Escalar a imagem manterá suas proporções originais. Se apenas uma das dimensões for dada, a outra será automaticamente calculada.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 660,
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: destaques_home.
  $styles['destaques_home'] = array(
    'name' => 'destaques_home',
    'effects' => array(
      1 => array(
        'label' => 'Escalar e cortar',
        'help' => '"Escalar e cortar", primeiro redimensiona a imagem mantendo a proporção e em seguida, vai cortará a dimensão maior. Isto é útil para criar miniaturas quadradas, sem esticar a imagem.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 660,
          'height' => 200,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'destaques_home',
  );

  // Exported image style: list_posts_150x150.
  $styles['list_posts_150x150'] = array(
    'name' => 'list_posts_150x150',
    'effects' => array(
      2 => array(
        'label' => 'Escalar e cortar',
        'help' => '"Escalar e cortar", primeiro redimensiona a imagem mantendo a proporção e em seguida, vai cortará a dimensão maior. Isto é útil para criar miniaturas quadradas, sem esticar a imagem.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 150,
          'height' => 150,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'list_posts_150x150',
  );

  // Exported image style: list_posts_207x150.
  $styles['list_posts_207x150'] = array(
    'name' => 'list_posts_207x150',
    'effects' => array(
      4 => array(
        'label' => 'Escalar e cortar',
        'help' => '"Escalar e cortar", primeiro redimensiona a imagem mantendo a proporção e em seguida, vai cortará a dimensão maior. Isto é útil para criar miniaturas quadradas, sem esticar a imagem.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 207,
          'height' => 150,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'list_posts_207x150',
  );

  // Exported image style: related_content_35x35.
  $styles['related_content_35x35'] = array(
    'name' => 'related_content_35x35',
    'effects' => array(
      3 => array(
        'label' => 'Escalar e cortar',
        'help' => '"Escalar e cortar", primeiro redimensiona a imagem mantendo a proporção e em seguida, vai cortará a dimensão maior. Isto é útil para criar miniaturas quadradas, sem esticar a imagem.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 35,
          'height' => 35,
        ),
        'weight' => 1,
      ),
    ),
    'label' => 'related_content_35x35',
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function fs_core_node_info() {
  $items = array(
    'page' => array(
      'name' => t('Página'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Título'),
      'help' => '',
    ),
    'webform' => array(
      'name' => t('Formulário'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Título'),
      'help' => '',
    ),
  );
  return $items;
}
