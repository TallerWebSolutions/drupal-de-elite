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
  $context->description = 'Cursos';
  $context->tag = 'common';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'curso' => 'curso',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'curso' => 'curso',
        'curso/*' => 'curso/*',
        'contato' => 'contato',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-help' => array(
          'module' => 'system',
          'delta' => 'help',
          'region' => 'help',
          'weight' => '-10',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views--exp-general_search-page' => array(
          'module' => 'views',
          'delta' => '-exp-general_search-page',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'boxes-chamada_cursos' => array(
          'module' => 'boxes',
          'delta' => 'chamada_cursos',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'boxes-curso_contato' => array(
          'module' => 'boxes',
          'delta' => 'curso_contato',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'views-courses-block' => array(
          'module' => 'views',
          'delta' => 'courses-block',
          'region' => 'content_bottom_1',
          'weight' => '-10',
        ),
        'views-courses-block_1' => array(
          'module' => 'views',
          'delta' => 'courses-block_1',
          'region' => 'content_bottom_2',
          'weight' => '-10',
        ),
        'views-courses-block_2' => array(
          'module' => 'views',
          'delta' => 'courses-block_2',
          'region' => 'content_bottom_3',
          'weight' => '-10',
        ),
        'simplified_social_share-open_sharing' => array(
          'module' => 'simplified_social_share',
          'delta' => 'open_sharing',
          'region' => 'share',
          'weight' => '-10',
        ),
        'disqus-disqus_comments' => array(
          'module' => 'disqus',
          'delta' => 'disqus_comments',
          'region' => 'bottom',
          'weight' => '-10',
        ),
        'boxes-rodape' => array(
          'module' => 'boxes',
          'delta' => 'rodape',
          'region' => 'footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Cursos');
  t('common');
  $export['cursos'] = $context;

  return $export;
}
