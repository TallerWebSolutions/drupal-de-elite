<?php
/**
 * @file
 * fs_cursos.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function fs_cursos_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'cursos';
  $context->description = '';
  $context->tag = 'curso';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'curso' => 'curso',
        'contato' => 'contato',
        'curso/*' => 'curso/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views-palestrante-block' => array(
          'module' => 'views',
          'delta' => 'palestrante-block',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'boxes-curso_chamada' => array(
          'module' => 'boxes',
          'delta' => 'curso_chamada',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'boxes-curso_contato' => array(
          'module' => 'boxes',
          'delta' => 'curso_contato',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'easy_social-easy_social_block_1' => array(
          'module' => 'easy_social',
          'delta' => 'easy_social_block_1',
          'region' => 'search_box',
          'weight' => '-9',
        ),
        'user-login' => array(
          'module' => 'user',
          'delta' => 'login',
          'region' => 'search_box',
          'weight' => '-8',
        ),
        'views-subscriptions-block' => array(
          'module' => 'views',
          'delta' => 'subscriptions-block',
          'region' => 'search_box',
          'weight' => '-7',
        ),
        'views-usuarios-block_1' => array(
          'module' => 'views',
          'delta' => 'usuarios-block_1',
          'region' => 'search_box',
          'weight' => '-6',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'system-help' => array(
          'module' => 'system',
          'delta' => 'help',
          'region' => 'help',
          'weight' => '-10',
        ),
        'views-cursos-block' => array(
          'module' => 'views',
          'delta' => 'cursos-block',
          'region' => 'footer_first',
          'weight' => '-10',
        ),
        'views-cursos-block_1' => array(
          'module' => 'views',
          'delta' => 'cursos-block_1',
          'region' => 'footer_second',
          'weight' => '-10',
        ),
        'views-cursos-block_2' => array(
          'module' => 'views',
          'delta' => 'cursos-block_2',
          'region' => 'footer_third',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('curso');
  $export['cursos'] = $context;

  return $export;
}
