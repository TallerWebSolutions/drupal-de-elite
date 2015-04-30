<?php
/**
 * @file
 * fs_blog.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function fs_blog_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'blogs';
  $context->description = '';
  $context->tag = 'blogs';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'blog' => 'blog',
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
        'views-posts-block_2' => array(
          'module' => 'views',
          'delta' => 'posts-block_2',
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
  t('blogs');
  $export['blogs'] = $context;

  return $export;
}
