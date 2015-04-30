<?php
/**
 * @file
 * fs_eventos.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function fs_eventos_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'eventos';
  $context->description = '';
  $context->tag = 'eventos';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'evento' => 'evento',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'evento' => 'evento',
        'evento/*' => 'evento/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-subscriptions-block' => array(
          'module' => 'views',
          'delta' => 'subscriptions-block',
          'region' => 'header',
          'weight' => '-8',
        ),
        'views-usuarios-block_1' => array(
          'module' => 'views',
          'delta' => 'usuarios-block_1',
          'region' => 'header',
          'weight' => '-7',
        ),
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
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-palestrante-block' => array(
          'module' => 'views',
          'delta' => 'palestrante-block',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-eventos-block_2' => array(
          'module' => 'views',
          'delta' => 'eventos-block_2',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'views-tags-block' => array(
          'module' => 'views',
          'delta' => 'tags-block',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'views-related_content-block_1' => array(
          'module' => 'views',
          'delta' => 'related_content-block_1',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
        'disqus-disqus_recent_comments' => array(
          'module' => 'disqus',
          'delta' => 'disqus_recent_comments',
          'region' => 'sidebar_second',
          'weight' => '-5',
        ),
        'easy_social-easy_social_block_1' => array(
          'module' => 'easy_social',
          'delta' => 'easy_social_block_1',
          'region' => 'footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('eventos');
  $export['eventos'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'lista_de_eventos';
  $context->description = '';
  $context->tag = 'eventos';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'evento' => 'evento',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-eventos-block_5' => array(
          'module' => 'views',
          'delta' => 'eventos-block_5',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-eventos-block_4' => array(
          'module' => 'views',
          'delta' => 'eventos-block_4',
          'region' => 'content',
          'weight' => '-9',
        ),
        'system-help' => array(
          'module' => 'system',
          'delta' => 'help',
          'region' => 'help',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('eventos');
  $export['lista_de_eventos'] = $context;

  return $export;
}
