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
  $context->description = '';
  $context->tag = 'all pages';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'podcast' => 'podcast',
        'blog' => 'blog',
        'video' => 'video',
        'arquivo' => 'arquivo',
        'arquivo/*' => 'arquivo/*',
        'tags' => 'tags',
        'tags/*' => 'tags/*',
        'acesso-negado' => 'acesso-negado',
        'pagina-nao-encontrada' => 'pagina-nao-encontrada',
        'busca' => 'busca',
        'busca/*' => 'busca/*',
        'search' => 'search',
        'search/*' => 'search/*',
        'search404' => 'search404',
        'search404/*' => 'search404/*',
        'search404*' => 'search404*',
        'page-not-found' => 'page-not-found',
        'page-not-found/*' => 'page-not-found/*',
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
        'views-tags-block' => array(
          'module' => 'views',
          'delta' => 'tags-block',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'views-banner-block' => array(
          'module' => 'views',
          'delta' => 'banner-block',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'boxes-facebook_likebox' => array(
          'module' => 'boxes',
          'delta' => 'facebook_likebox',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('all pages');
  $export['allpages'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'home';
  $context->description = '';
  $context->tag = 'homepage';
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
        'views-banner-block' => array(
          'module' => 'views',
          'delta' => 'banner-block',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'boxes-facebook_likebox' => array(
          'module' => 'boxes',
          'delta' => 'facebook_likebox',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('homepage');
  $export['home'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'node_view';
  $context->description = 'Contempla os blocos que constituem a pagina do node';
  $context->tag = 'nodeview';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'blog' => 'blog',
        'podcast' => 'podcast',
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
        'views-tags-block' => array(
          'module' => 'views',
          'delta' => 'tags-block',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'views-related_content-block_1' => array(
          'module' => 'views',
          'delta' => 'related_content-block_1',
          'region' => 'sidebar_second',
          'weight' => '-7',
        ),
        'boxes-facebook_likebox' => array(
          'module' => 'boxes',
          'delta' => 'facebook_likebox',
          'region' => 'sidebar_second',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Contempla os blocos que constituem a pagina do node');
  t('nodeview');
  $export['node_view'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'some_pages';
  $context->description = '';
  $context->tag = 'somepages';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'sobre' => 'sobre',
        'node/4/done' => 'node/4/done',
        'node/4/done/*' => 'node/4/done/*',
        'node/40' => 'node/40',
        'user' => 'user',
        'user/*' => 'user/*',
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
        'views-subscriptions-block_1' => array(
          'module' => 'views',
          'delta' => 'subscriptions-block_1',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-eventos-block_3' => array(
          'module' => 'views',
          'delta' => 'eventos-block_3',
          'region' => 'content',
          'weight' => '-8',
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'boxes-facebook_likebox' => array(
          'module' => 'boxes',
          'delta' => 'facebook_likebox',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('somepages');
  $export['some_pages'] = $context;

  return $export;
}
