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
  $context->description = 'Eventos';
  $context->tag = 'common';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'evento' => 'evento',
      ),
      'options' => array(
        'node_form' => '0',
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
        'views-palestrante-block' => array(
          'module' => 'views',
          'delta' => 'palestrante-block',
          'region' => 'sidebar_second',
          'weight' => '-9',
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
  t('Eventos');
  t('common');
  $export['eventos'] = $context;

  return $export;
}
