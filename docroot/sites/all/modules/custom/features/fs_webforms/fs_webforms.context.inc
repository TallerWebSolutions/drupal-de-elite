<?php
/**
 * @file
 * fs_webforms.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function fs_webforms_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'webforms';
  $context->description = '';
  $context->tag = 'webforms';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'webform' => 'webform',
      ),
      'options' => array(
        'node_form' => '1',
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
        'boxes-curso_chamada' => array(
          'module' => 'boxes',
          'delta' => 'curso_chamada',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'boxes-curso_contato' => array(
          'module' => 'boxes',
          'delta' => 'curso_contato',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'easy_social-easy_social_block_1' => array(
          'module' => 'easy_social',
          'delta' => 'easy_social_block_1',
          'region' => 'search_box',
          'weight' => '-34',
        ),
        'user-login' => array(
          'module' => 'user',
          'delta' => 'login',
          'region' => 'search_box',
          'weight' => '-33',
        ),
        'views-subscriptions-block' => array(
          'module' => 'views',
          'delta' => 'subscriptions-block',
          'region' => 'search_box',
          'weight' => '-32',
        ),
        'views-usuarios-block_1' => array(
          'module' => 'views',
          'delta' => 'usuarios-block_1',
          'region' => 'search_box',
          'weight' => '-31',
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
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('webforms');
  $export['webforms'] = $context;

  return $export;
}
