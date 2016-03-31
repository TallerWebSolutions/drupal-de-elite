<?php
/**
 * @file
 * fs_core.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function fs_core_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'allpages';
  $context->description = 'All pages';
  $context->tag = 'common';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '*' => '*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-general_search-page' => array(
          'module' => 'views',
          'delta' => '-exp-general_search-page',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'facetapi-IPaCM7H1dF7Clj1WBtiZQw516MCvTYka' => array(
          'module' => 'facetapi',
          'delta' => 'IPaCM7H1dF7Clj1WBtiZQw516MCvTYka',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'boxes-youtube_subscribe' => array(
          'module' => 'boxes',
          'delta' => 'youtube_subscribe',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'boxes-facebook_widget' => array(
          'module' => 'boxes',
          'delta' => 'facebook_widget',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'boxes-twitter_widget' => array(
          'module' => 'boxes',
          'delta' => 'twitter_widget',
          'region' => 'sidebar_second',
          'weight' => '-6',
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
  t('All pages');
  t('common');
  $export['allpages'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'home';
  $context->description = 'Home';
  $context->tag = 'common';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-home_presentation' => array(
          'module' => 'boxes',
          'delta' => 'home_presentation',
          'region' => 'content',
          'weight' => '-10',
        ),
        'boxes-quem_somos' => array(
          'module' => 'boxes',
          'delta' => 'quem_somos',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Home');
  t('common');
  $export['home'] = $context;

  return $export;
}
