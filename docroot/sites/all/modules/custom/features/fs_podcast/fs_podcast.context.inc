<?php
/**
 * @file
 * fs_podcast.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function fs_podcast_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'podcasts';
  $context->description = '';
  $context->tag = 'podcasts';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'podcast' => 'podcast',
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
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'views-autor-block' => array(
          'module' => 'views',
          'delta' => 'autor-block',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-podcast-block_1' => array(
          'module' => 'views',
          'delta' => 'podcast-block_1',
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
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('podcasts');
  $export['podcasts'] = $context;

  return $export;
}
