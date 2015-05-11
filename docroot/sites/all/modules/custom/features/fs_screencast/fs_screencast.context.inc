<?php
/**
 * @file
 * fs_screencast.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function fs_screencast_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'videos';
  $context->description = '';
  $context->tag = 'videos';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'screencast' => 'screencast',
      ),
      'options' => array(
        'node_form' => '0',
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
        'views-autor-block' => array(
          'module' => 'views',
          'delta' => 'autor-block',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-videos-block_1' => array(
          'module' => 'views',
          'delta' => 'videos-block_1',
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
  t('videos');
  $export['videos'] = $context;

  return $export;
}
