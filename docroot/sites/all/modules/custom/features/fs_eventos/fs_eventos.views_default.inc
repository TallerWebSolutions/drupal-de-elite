<?php
/**
 * @file
 * fs_eventos.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function fs_eventos_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'palestrante';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Palestrante';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Quem ministra';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mais';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Restaurar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Crescente';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relação: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_palestrante_target_id']['id'] = 'field_palestrante_target_id';
  $handler->display->display_options['relationships']['field_palestrante_target_id']['table'] = 'field_data_field_palestrante';
  $handler->display->display_options['relationships']['field_palestrante_target_id']['field'] = 'field_palestrante_target_id';
  $handler->display->display_options['relationships']['field_palestrante_target_id']['label'] = 'palestrante';
  $handler->display->display_options['relationships']['field_palestrante_target_id']['required'] = TRUE;
  /* Campo: Usuário: Foto */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'field_palestrante_target_id';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['picture']['alter']['text'] = '[picture]';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['empty'] = '<img src="/sites/all/themes/delite/images/avatar-35.jpg">';
  $handler->display->display_options['fields']['picture']['image_style'] = 'large';
  /* Campo: Campo: Nome real */
  $handler->display->display_options['fields']['field_realname']['id'] = 'field_realname';
  $handler->display->display_options['fields']['field_realname']['table'] = 'field_data_field_realname';
  $handler->display->display_options['fields']['field_realname']['field'] = 'field_realname';
  $handler->display->display_options['fields']['field_realname']['relationship'] = 'field_palestrante_target_id';
  $handler->display->display_options['fields']['field_realname']['label'] = '';
  $handler->display->display_options['fields']['field_realname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_realname']['alter']['text'] = '<strong>[field_realname]</strong>';
  $handler->display->display_options['fields']['field_realname']['alter']['path'] = '[view_user]';
  $handler->display->display_options['fields']['field_realname']['element_label_colon'] = FALSE;
  /* Campo: Usuário: Link */
  $handler->display->display_options['fields']['view_user']['id'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['table'] = 'users';
  $handler->display->display_options['fields']['view_user']['field'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['relationship'] = 'field_palestrante_target_id';
  $handler->display->display_options['fields']['view_user']['label'] = '';
  $handler->display->display_options['fields']['view_user']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['view_user']['alter']['text'] = '<h4>[field_realname]</h4>';
  $handler->display->display_options['fields']['view_user']['element_label_colon'] = FALSE;
  /* Campo: Usuário: Sobre */
  $handler->display->display_options['fields']['field_about']['id'] = 'field_about';
  $handler->display->display_options['fields']['field_about']['table'] = 'field_data_field_about';
  $handler->display->display_options['fields']['field_about']['field'] = 'field_about';
  $handler->display->display_options['fields']['field_about']['relationship'] = 'field_palestrante_target_id';
  $handler->display->display_options['fields']['field_about']['label'] = '';
  $handler->display->display_options['fields']['field_about']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_about']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_about']['settings'] = array(
    'trim_length' => '250',
  );
  /* Campo: Usuário: Drupal.org */
  $handler->display->display_options['fields']['field_drupal_org']['id'] = 'field_drupal_org';
  $handler->display->display_options['fields']['field_drupal_org']['table'] = 'field_data_field_drupal_org';
  $handler->display->display_options['fields']['field_drupal_org']['field'] = 'field_drupal_org';
  $handler->display->display_options['fields']['field_drupal_org']['relationship'] = 'field_palestrante_target_id';
  $handler->display->display_options['fields']['field_drupal_org']['label'] = '';
  $handler->display->display_options['fields']['field_drupal_org']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_drupal_org']['alter']['text'] = '<div class="perfil-drupal-org">
<a href="http://drupal.org/user/[field_drupal_org]">drupal.org/user/[field_drupal_org]</a>
</div>';
  $handler->display->display_options['fields']['field_drupal_org']['element_label_colon'] = FALSE;
  /* Campo: Usuário: Facebook */
  $handler->display->display_options['fields']['field_facebook']['id'] = 'field_facebook';
  $handler->display->display_options['fields']['field_facebook']['table'] = 'field_data_field_facebook';
  $handler->display->display_options['fields']['field_facebook']['field'] = 'field_facebook';
  $handler->display->display_options['fields']['field_facebook']['relationship'] = 'field_palestrante_target_id';
  $handler->display->display_options['fields']['field_facebook']['label'] = '';
  $handler->display->display_options['fields']['field_facebook']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_facebook']['alter']['text'] = '<div class="author-facebook">
<a href="http://facebook.com/[field_facebook]">facebook.com/[field_facebook]</a>
</div>';
  $handler->display->display_options['fields']['field_facebook']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_facebook']['element_label_colon'] = FALSE;
  /* Campo: Usuário: Twitter */
  $handler->display->display_options['fields']['field_twitter']['id'] = 'field_twitter';
  $handler->display->display_options['fields']['field_twitter']['table'] = 'field_data_field_twitter';
  $handler->display->display_options['fields']['field_twitter']['field'] = 'field_twitter';
  $handler->display->display_options['fields']['field_twitter']['relationship'] = 'field_palestrante_target_id';
  $handler->display->display_options['fields']['field_twitter']['label'] = '';
  $handler->display->display_options['fields']['field_twitter']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_twitter']['alter']['text'] = '<div class="author-twitter">
<a href="http://twitter.com/[field_twitter]">@[field_twitter]</a>
</div>';
  $handler->display->display_options['fields']['field_twitter']['alter']['path'] = '[field_twitter]';
  $handler->display->display_options['fields']['field_twitter']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_twitter']['element_label_colon'] = FALSE;
  /* Campo: Usuário: Google+ */
  $handler->display->display_options['fields']['field_google']['id'] = 'field_google';
  $handler->display->display_options['fields']['field_google']['table'] = 'field_data_field_google';
  $handler->display->display_options['fields']['field_google']['field'] = 'field_google';
  $handler->display->display_options['fields']['field_google']['relationship'] = 'field_palestrante_target_id';
  $handler->display->display_options['fields']['field_google']['label'] = '';
  $handler->display->display_options['fields']['field_google']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_google']['alter']['text'] = '<div class="author-gplus">
<a href="https://plus.google.com/[field_google]">plus.google.com/[field_google]</a>
</div>';
  $handler->display->display_options['fields']['field_google']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_google']['element_label_colon'] = FALSE;
  /* Campo: Usuário: YouTube */
  $handler->display->display_options['fields']['field_youtube']['id'] = 'field_youtube';
  $handler->display->display_options['fields']['field_youtube']['table'] = 'field_data_field_youtube';
  $handler->display->display_options['fields']['field_youtube']['field'] = 'field_youtube';
  $handler->display->display_options['fields']['field_youtube']['relationship'] = 'field_palestrante_target_id';
  $handler->display->display_options['fields']['field_youtube']['label'] = '';
  $handler->display->display_options['fields']['field_youtube']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_youtube']['alter']['text'] = '<div class="author-youtube">
<a href="http://youtube.com/[field_youtube]">youtube.com/[field_youtube]</a>
</div>';
  $handler->display->display_options['fields']['field_youtube']['alter']['path'] = '[field_youtube]';
  $handler->display->display_options['fields']['field_youtube']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_youtube']['element_label_colon'] = FALSE;
  /* Campo: Usuário: Vimeo */
  $handler->display->display_options['fields']['field_vimeo']['id'] = 'field_vimeo';
  $handler->display->display_options['fields']['field_vimeo']['table'] = 'field_data_field_vimeo';
  $handler->display->display_options['fields']['field_vimeo']['field'] = 'field_vimeo';
  $handler->display->display_options['fields']['field_vimeo']['relationship'] = 'field_palestrante_target_id';
  $handler->display->display_options['fields']['field_vimeo']['label'] = '';
  $handler->display->display_options['fields']['field_vimeo']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_vimeo']['alter']['text'] = '<div class="author-vimeo">
<a href="http://vimeo.com/[field_vimeo]">vimeo.com/[field_vimeo]</a>
</div>';
  $handler->display->display_options['fields']['field_vimeo']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['field_vimeo']['element_label_colon'] = FALSE;
  /* Critério de ordenação: Conteúdo: Data de publicação */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filtro contextual: Conteúdo: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Tudo';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $translatables['palestrante'] = array(
    t('Master'),
    t('Quem ministra'),
    t('mais'),
    t('Aplicar'),
    t('Restaurar'),
    t('Ordenar por'),
    t('Crescente'),
    t('Desc'),
    t('palestrante'),
    t('[picture]'),
    t('<img src="/sites/all/themes/delite/images/avatar-35.jpg">'),
    t('<strong>[field_realname]</strong>'),
    t('<h4>[field_realname]</h4>'),
    t('<div class="perfil-drupal-org">
<a href="http://drupal.org/user/[field_drupal_org]">drupal.org/user/[field_drupal_org]</a>
</div>'),
    t('<div class="author-facebook">
<a href="http://facebook.com/[field_facebook]">facebook.com/[field_facebook]</a>
</div>'),
    t('<div class="author-twitter">
<a href="http://twitter.com/[field_twitter]">@[field_twitter]</a>
</div>'),
    t('<div class="author-gplus">
<a href="https://plus.google.com/[field_google]">plus.google.com/[field_google]</a>
</div>'),
    t('<div class="author-youtube">
<a href="http://youtube.com/[field_youtube]">youtube.com/[field_youtube]</a>
</div>'),
    t('<div class="author-vimeo">
<a href="http://vimeo.com/[field_vimeo]">vimeo.com/[field_vimeo]</a>
</div>'),
    t('Tudo'),
    t('Block'),
  );
  $export['palestrante'] = $view;

  return $export;
}
