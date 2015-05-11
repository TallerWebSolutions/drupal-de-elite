<?php
/**
 * @file
 * fs_core.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function fs_core_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'autor';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Autor';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Sobre o autor';
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
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relação: Conteúdo: Autor */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Campo: Usuário: Foto */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'uid';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['empty'] = '<img src="/sites/all/themes/delite/images/avatar-35.jpg">';
  $handler->display->display_options['fields']['picture']['image_style'] = 'list_posts_150x150';
  /* Campo: Usuário: Nome real */
  $handler->display->display_options['fields']['field_realname']['id'] = 'field_realname';
  $handler->display->display_options['fields']['field_realname']['table'] = 'field_data_field_realname';
  $handler->display->display_options['fields']['field_realname']['field'] = 'field_realname';
  $handler->display->display_options['fields']['field_realname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_realname']['label'] = '';
  $handler->display->display_options['fields']['field_realname']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_realname']['element_label_colon'] = FALSE;
  /* Campo: Usuário: Link */
  $handler->display->display_options['fields']['view_user']['id'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['table'] = 'users';
  $handler->display->display_options['fields']['view_user']['field'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['relationship'] = 'uid';
  $handler->display->display_options['fields']['view_user']['label'] = '';
  $handler->display->display_options['fields']['view_user']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['view_user']['alter']['text'] = '[field_realname]';
  $handler->display->display_options['fields']['view_user']['element_label_colon'] = FALSE;
  /* Campo: Usuário: Sobre */
  $handler->display->display_options['fields']['field_about']['id'] = 'field_about';
  $handler->display->display_options['fields']['field_about']['table'] = 'field_data_field_about';
  $handler->display->display_options['fields']['field_about']['field'] = 'field_about';
  $handler->display->display_options['fields']['field_about']['relationship'] = 'uid';
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
  $handler->display->display_options['fields']['field_drupal_org']['relationship'] = 'uid';
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
  $handler->display->display_options['fields']['field_facebook']['relationship'] = 'uid';
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
  $handler->display->display_options['fields']['field_twitter']['relationship'] = 'uid';
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
  $handler->display->display_options['fields']['field_google']['relationship'] = 'uid';
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
  $handler->display->display_options['fields']['field_youtube']['relationship'] = 'uid';
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
  $handler->display->display_options['fields']['field_vimeo']['relationship'] = 'uid';
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
  /* Filter criterion: Conteúdo: Publicado */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $translatables['autor'] = array(
    t('Master'),
    t('Sobre o autor'),
    t('mais'),
    t('Aplicar'),
    t('Restaurar'),
    t('Ordenar por'),
    t('Crescente'),
    t('Desc'),
    t('autor'),
    t('<img src="/sites/all/themes/delite/images/avatar-35.jpg">'),
    t('[field_realname]'),
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
  $export['autor'] = $view;

  $view = new view();
  $view->name = 'destaques';
  $view->description = 'View para conteúdo em destaque';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Destaques';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
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
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'views_nivo_slider';
  $handler->display->display_options['style_options']['nivo_version'] = '3.x';
  $handler->display->display_options['style_options']['effect'] = array(
    'random' => 'random',
  );
  $handler->display->display_options['style_options']['pauseTime'] = '7000';
  $handler->display->display_options['style_options']['controlNavThumbsField'] = 'title';
  $handler->display->display_options['style_options']['controlNavThumbsIC'] = 'destaques_home';
  $handler->display->display_options['row_plugin'] = 'nivo_sliderfields';
  $handler->display->display_options['row_options']['image_field'] = 'field_image';
  $handler->display->display_options['row_options']['title_field'] = 'title';
  $handler->display->display_options['row_options']['link_field'] = 'title';
  /* Relação: Flags: hightlight */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'hightlight';
  /* Campo: Conteúdo: Título */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Campo: Conteúdo: Imagem de chamada */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'destaques_home',
    'image_link' => 'content',
  );
  /* Critério de ordenação: Conteúdo: Data de publicação */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Conteúdo: Publicado */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $translatables['destaques'] = array(
    t('Master'),
    t('mais'),
    t('Aplicar'),
    t('Restaurar'),
    t('Ordenar por'),
    t('Crescente'),
    t('Desc'),
    t('flag'),
    t('Block'),
  );
  $export['destaques'] = $view;

  $view = new view();
  $view->name = 'home_page';
  $view->description = 'Emulates the default Drupal front page; you may set the default home page path to this view to make it your front page.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Home page';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mais';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Restaurar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Crescente';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '7';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '5';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Itens por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todos -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Deslocamento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '««« ';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '«';
  $handler->display->display_options['pager']['options']['tags']['next'] = '»';
  $handler->display->display_options['pager']['options']['tags']['last'] = '»»»';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['uses_fields'] = TRUE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Campo: Conteúdo: Título */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<h2>[title]</h2>';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Campo: Conteúdo: Imagem de chamada */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'list_posts_150x150',
    'image_link' => 'content',
  );
  /* Campo: Conteúdo: Descrição */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_description']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_description']['settings'] = array(
    'trim_length' => '200',
  );
  /* Campo: Conteúdo: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Leia mais';
  /* Campo: Conteúdo: Disqus Comment Count */
  $handler->display->display_options['fields']['disqus_comment_count']['id'] = 'disqus_comment_count';
  $handler->display->display_options['fields']['disqus_comment_count']['table'] = 'node';
  $handler->display->display_options['fields']['disqus_comment_count']['field'] = 'disqus_comment_count';
  $handler->display->display_options['fields']['disqus_comment_count']['label'] = '';
  $handler->display->display_options['fields']['disqus_comment_count']['element_label_colon'] = FALSE;
  /* Campo: Conteúdo: Tags */
  $handler->display->display_options['fields']['field_tags']['id'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['table'] = 'field_data_field_tags';
  $handler->display->display_options['fields']['field_tags']['field'] = 'field_tags';
  $handler->display->display_options['fields']['field_tags']['label'] = '';
  $handler->display->display_options['fields']['field_tags']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tags']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_tags']['multi_type'] = 'ul';
  /* Critério de ordenação: Conteúdo: Destacado */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Critério de ordenação: Conteúdo: Data de publicação */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Conteúdo: Promovido para a página inicial */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'node';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $handler->display->display_options['filters']['promote']['group'] = 0;
  $handler->display->display_options['filters']['promote']['expose']['operator'] = FALSE;
  /* Filter criterion: Conteúdo: Publicado */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'home';
  $translatables['home_page'] = array(
    t('Master'),
    t('mais'),
    t('Aplicar'),
    t('Restaurar'),
    t('Ordenar por'),
    t('Crescente'),
    t('Desc'),
    t('Itens por página'),
    t('- Todos -'),
    t('Deslocamento'),
    t('««« '),
    t('«'),
    t('»'),
    t('»»»'),
    t('<h2>[title]</h2>'),
    t('Leia mais'),
    t('Page'),
  );
  $export['home_page'] = $view;

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
  $handler->display->display_options['fields']['picture']['image_style'] = 'related_content_35x35';
  /* Campo: Usuário: Nome real */
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
  $handler->display->display_options['fields']['view_user']['alter']['text'] = '[field_realname]';
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
  /* Filter criterion: Conteúdo: Publicado */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

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
    t('[field_realname]'),
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

  $view = new view();
  $view->name = 'related_content';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Conteúdo relacionado';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
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
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Campo: Conteúdo: Título */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Campo: Handler quebrado ou não encontrado */
  $handler->display->display_options['fields']['field_foto']['id'] = 'field_foto';
  $handler->display->display_options['fields']['field_foto']['table'] = 'field_data_field_foto';
  $handler->display->display_options['fields']['field_foto']['field'] = 'field_foto';
  $handler->display->display_options['fields']['field_foto']['label'] = '';
  $handler->display->display_options['fields']['field_foto']['element_label_colon'] = FALSE;
  /* Campo: Conteúdo: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '230';
  $handler->display->display_options['fields']['body']['alter']['more_link_text'] = 'Leia mais';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Campo: Conteúdo: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['view_node']['alter']['text'] = '[body]';
  $handler->display->display_options['fields']['view_node']['alter']['max_length'] = '230';
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  /* Critério de ordenação: Conteúdo: Data de publicação */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filtro contextual: Conteúdo: Tem ID de termo de taxonomia */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Tudo';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['code'] = '$node=node_load(arg(1));
if($node){
foreach($node->taxonomy as $term){$terms[]=$term->tid;}
return implode(\'+\',$terms);
}else {return;}';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'php';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = TRUE;
  $handler->display->display_options['arguments']['tid']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Conteúdo: Publicado */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Conteúdo: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'podcast' => 'podcast',
    'blog' => 'blog',
    'screencast' => 'screencast',
  );

  /* Display: Bloco */
  $handler = $view->new_display('block', 'Bloco', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Conteúdo relacionado';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Campo: Conteúdo: Imagem de chamada */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'list_posts_150x150',
    'image_link' => 'content',
  );
  /* Campo: Conteúdo: Título */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Filtro contextual: Conteúdo: Tem ID de termo de taxonomia */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['exception']['title'] = 'Tudo';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['code'] = '$node=node_load(arg(1));
  
  if($node){
    foreach($node->field_tags[\'und\'] as $term) {
      $terms[] = $term[\'tid\'];
    }
    return implode(\'+\',$terms);
  }
  else {
    return;
  }';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['break_phrase'] = TRUE;
  $handler->display->display_options['arguments']['tid']['add_table'] = TRUE;
  $handler->display->display_options['arguments']['tid']['reduce_duplicates'] = TRUE;
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
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Conteúdo: Publicado */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Conteúdo: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'evento' => 'evento',
    'podcast' => 'podcast',
    'blog' => 'blog',
    'screencast' => 'screencast',
  );
  $translatables['related_content'] = array(
    t('Master'),
    t('mais'),
    t('Aplicar'),
    t('Restaurar'),
    t('Ordenar por'),
    t('Crescente'),
    t('Desc'),
    t('Leia mais'),
    t('[body]'),
    t('Tudo'),
    t('Bloco'),
    t('Conteúdo relacionado'),
  );
  $export['related_content'] = $view;

  $view = new view();
  $view->name = 'search_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Search view';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Busca';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mais';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Buscar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Restaurar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Crescente';
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '7';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '5';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Itens por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todos -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Deslocamento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '«««';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '«';
  $handler->display->display_options['pager']['options']['tags']['next'] = '»';
  $handler->display->display_options['pager']['options']['tags']['last'] = '»»»';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Relação: Conteúdo: Autor */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Campo: Conteúdo: Título */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Campo: Conteúdo: Imagem de chamada */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'related_content_35x35',
    'image_link' => 'content',
  );
  /* Campo: Conteúdo: Descrição */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_description']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_description']['settings'] = array(
    'trim_length' => '180',
  );
  /* Campo: Conteúdo: Data de atualização */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Atualizado em';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Campo: Usuário: Nome */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Autor';
  /* Critério de ordenação: Conteúdo: Data de publicação */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filtro contextual: Buscar: Termos de busca */
  $handler->display->display_options['arguments']['keys']['id'] = 'keys';
  $handler->display->display_options['arguments']['keys']['table'] = 'search_index';
  $handler->display->display_options['arguments']['keys']['field'] = 'keys';
  $handler->display->display_options['arguments']['keys']['default_action'] = 'default';
  $handler->display->display_options['arguments']['keys']['exception']['title'] = 'Tudo';
  $handler->display->display_options['arguments']['keys']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['keys']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['keys']['default_argument_options']['use_alias'] = TRUE;
  $handler->display->display_options['arguments']['keys']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['keys']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['keys']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Conteúdo: Publicado */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Conteúdo: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'curso' => 'curso',
    'evento' => 'evento',
    'podcast' => 'podcast',
    'blog' => 'blog',
    'screencast' => 'screencast',
  );
  $translatables['search_view'] = array(
    t('Master'),
    t('Busca'),
    t('mais'),
    t('Buscar'),
    t('Restaurar'),
    t('Ordenar por'),
    t('Crescente'),
    t('Desc'),
    t('Itens por página'),
    t('- Todos -'),
    t('Deslocamento'),
    t('«««'),
    t('«'),
    t('»'),
    t('»»»'),
    t('autor'),
    t('Atualizado em'),
    t('Autor'),
    t('Tudo'),
  );
  $export['search_view'] = $view;

  $view = new view();
  $view->name = 'sort_shirts';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Sorteio Camisetas Drupal de Elite';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Sorteio Camisetas Drupal de Elite';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mais';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Restaurar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Crescente';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relação: Flags: User's flagged content */
  $handler->display->display_options['relationships']['flag_user_content_rel']['id'] = 'flag_user_content_rel';
  $handler->display->display_options['relationships']['flag_user_content_rel']['table'] = 'users';
  $handler->display->display_options['relationships']['flag_user_content_rel']['field'] = 'flag_user_content_rel';
  $handler->display->display_options['relationships']['flag_user_content_rel']['flag'] = 'subscribe';
  /* Relação: Flags: Usuário */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'flag_content';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['relationship'] = 'flag_user_content_rel';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Campo: Usuário: Nome */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Campo: Flags: User uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'flag_content';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'flag_user_content_rel';
  /* Critério de ordenação: Global: Aleatório */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Filter criterion: Usuário: Ativo */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/sorteio-camisetas';
  $translatables['sort_shirts'] = array(
    t('Master'),
    t('Sorteio Camisetas Drupal de Elite'),
    t('mais'),
    t('Aplicar'),
    t('Restaurar'),
    t('Ordenar por'),
    t('Crescente'),
    t('Desc'),
    t('user flagged content'),
    t('Flag user'),
    t('User uid'),
    t('Page'),
  );
  $export['sort_shirts'] = $view;

  $view = new view();
  $view->name = 'subscriptions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Subscriptions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Subscriptions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mais';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Restaurar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Crescente';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Itens por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todos -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Deslocamento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« início';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ anterior';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'próximo ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'fim »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'type' => 'type',
    'title' => 'title',
    'ops' => 'ops',
  );
  $handler->display->display_options['row_options']['separator'] = ' | ';
  /* Rodapé: Global: Área de texto */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '[uid]';
  $handler->display->display_options['footer']['area']['format'] = 'filtered_html';
  $handler->display->display_options['footer']['area']['tokenize'] = TRUE;
  /* Comportamento quando sem resultados: Global: Área de texto */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Você ainda não tem nenhuma inscrição. Se inscreva em um <a href="/curso">curso</a> ou em um <a href="/evento">evento</a>.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relação: Flags: subscribe */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'subscribe';
  /* Campo: Conteúdo: Tipo */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Campo: Conteúdo: Título */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Campo: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flag_content';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  /* Critério de ordenação: Flags: Flagged time */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'flag_content';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Filter criterion: Conteúdo: Publicado */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Minhas inscrições';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'Mais';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Campo: Conteúdo: Tipo */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Campo: Conteúdo: Título */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '40';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Campo: Flags: User uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'flag_content';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = 'Mais';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Inscrições';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'Mais';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Itens por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todos -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Deslocamento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« início';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ anterior';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'próximo ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'fim »';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Comportamento quando sem resultados: Global: Área de texto */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'Ainda não tem nenhuma inscrição.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relação: Flags: subscribe */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'subscribe';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Campo: Conteúdo: Tipo */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  /* Campo: Conteúdo: Título */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Campo: Flags: User uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'flag_content';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['uid']['alter']['text'] = 'Mais';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Filtro contextual: Flags: User uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'flag_content';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Tudo';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $translatables['subscriptions'] = array(
    t('Master'),
    t('Subscriptions'),
    t('mais'),
    t('Aplicar'),
    t('Restaurar'),
    t('Ordenar por'),
    t('Crescente'),
    t('Desc'),
    t('Itens por página'),
    t('- Todos -'),
    t('Deslocamento'),
    t('« início'),
    t('‹ anterior'),
    t('próximo ›'),
    t('fim »'),
    t('[uid]'),
    t('Você ainda não tem nenhuma inscrição. Se inscreva em um <a href="/curso">curso</a> ou em um <a href="/evento">evento</a>.'),
    t('flag'),
    t('Block'),
    t('Minhas inscrições'),
    t('Mais'),
    t('Inscrições'),
    t('Ainda não tem nenhuma inscrição.'),
    t('Tudo'),
  );
  $export['subscriptions'] = $view;

  $view = new view();
  $view->name = 'tags';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Tags';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Tags';
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
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'name' => 'name',
  );
  /* Campo: Termo de taxonomia: Nome */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Critério de ordenação: Global: Aleatório */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Filter criterion: Vocabulário de taxonomia: Nome no sistema */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'tags' => 'tags',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $translatables['tags'] = array(
    t('Master'),
    t('Tags'),
    t('mais'),
    t('Aplicar'),
    t('Restaurar'),
    t('Ordenar por'),
    t('Crescente'),
    t('Desc'),
    t('Block'),
  );
  $export['tags'] = $view;

  $view = new view();
  $view->name = 'usuarios';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Usuarios';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Autores';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mais';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Restaurar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Crescente';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Itens por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todos -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Deslocamento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« início';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ anterior';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'próximo ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'fim »';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Campo: Usuário: Foto */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['empty'] = '<img src="/sites/all/themes/delite/images/avatar-150.jpg">';
  $handler->display->display_options['fields']['picture']['image_style'] = 'list_posts_150x150';
  /* Campo: Usuário: Nome */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Campo: Usuário: Sobre */
  $handler->display->display_options['fields']['field_about']['id'] = 'field_about';
  $handler->display->display_options['fields']['field_about']['table'] = 'field_data_field_about';
  $handler->display->display_options['fields']['field_about']['field'] = 'field_about';
  $handler->display->display_options['fields']['field_about']['label'] = '';
  $handler->display->display_options['fields']['field_about']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_about']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_about']['settings'] = array(
    'trim_length' => '100',
  );
  /* Critério de ordenação: Usuário: Data de criação */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Filter criterion: Usuário: Ativo */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;

  /* Display: Página */
  $handler = $view->new_display('page', 'Página', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '%1';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'picture' => 'picture',
    'field_about' => 'field_about',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Campo: Usuário: Foto */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['empty'] = '<img src="/sites/all/themes/delite/images/avatar-150.jpg">';
  $handler->display->display_options['fields']['picture']['image_style'] = 'list_posts_150x150';
  /* Campo: Usuário: Nome real */
  $handler->display->display_options['fields']['field_realname']['id'] = 'field_realname';
  $handler->display->display_options['fields']['field_realname']['table'] = 'field_data_field_realname';
  $handler->display->display_options['fields']['field_realname']['field'] = 'field_realname';
  $handler->display->display_options['fields']['field_realname']['label'] = '';
  $handler->display->display_options['fields']['field_realname']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_realname']['alter']['text'] = '<div class="image-name-patente-user">
  <div class="image-user">[picture]</div>
  <div class="name-user">[field_realname]</div>
</div>';
  $handler->display->display_options['fields']['field_realname']['element_label_colon'] = FALSE;
  /* Campo: Usuário: Sobre */
  $handler->display->display_options['fields']['field_about']['id'] = 'field_about';
  $handler->display->display_options['fields']['field_about']['table'] = 'field_data_field_about';
  $handler->display->display_options['fields']['field_about']['field'] = 'field_about';
  $handler->display->display_options['fields']['field_about']['label'] = '';
  $handler->display->display_options['fields']['field_about']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_about']['settings'] = array(
    'trim_length' => '100',
  );
  /* Campo: Usuário: Mais */
  $handler->display->display_options['fields']['field_more']['id'] = 'field_more';
  $handler->display->display_options['fields']['field_more']['table'] = 'field_data_field_more';
  $handler->display->display_options['fields']['field_more']['field'] = 'field_more';
  $handler->display->display_options['fields']['field_more']['label'] = '';
  $handler->display->display_options['fields']['field_more']['element_label_colon'] = FALSE;
  /* Campo: Usuário: Drupal.org */
  $handler->display->display_options['fields']['field_drupal_org']['id'] = 'field_drupal_org';
  $handler->display->display_options['fields']['field_drupal_org']['table'] = 'field_data_field_drupal_org';
  $handler->display->display_options['fields']['field_drupal_org']['field'] = 'field_drupal_org';
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
  $handler->display->display_options['fields']['field_facebook']['label'] = '';
  $handler->display->display_options['fields']['field_facebook']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_facebook']['alter']['text'] = '<div class="author-facebook">
<a href="http://facebook.com/[field_facebook]">facebook.com/[field_facebook]</a>
</div>';
  $handler->display->display_options['fields']['field_facebook']['element_label_colon'] = FALSE;
  /* Campo: Usuário: Google+ */
  $handler->display->display_options['fields']['field_google']['id'] = 'field_google';
  $handler->display->display_options['fields']['field_google']['table'] = 'field_data_field_google';
  $handler->display->display_options['fields']['field_google']['field'] = 'field_google';
  $handler->display->display_options['fields']['field_google']['label'] = '';
  $handler->display->display_options['fields']['field_google']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_google']['alter']['text'] = '<div class="author-gplus">
<a href="https://plus.google.com/[field_google]">plus.google.com/[field_google]</a>
</div>';
  $handler->display->display_options['fields']['field_google']['element_label_colon'] = FALSE;
  /* Campo: Usuário: Twitter */
  $handler->display->display_options['fields']['field_twitter']['id'] = 'field_twitter';
  $handler->display->display_options['fields']['field_twitter']['table'] = 'field_data_field_twitter';
  $handler->display->display_options['fields']['field_twitter']['field'] = 'field_twitter';
  $handler->display->display_options['fields']['field_twitter']['label'] = '';
  $handler->display->display_options['fields']['field_twitter']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_twitter']['alter']['text'] = '<div class="author-twitter">
<a href="http://twitter.com/[field_twitter]">@[field_twitter]</a>
</div>';
  $handler->display->display_options['fields']['field_twitter']['element_label_colon'] = FALSE;
  /* Campo: Usuário: Vimeo */
  $handler->display->display_options['fields']['field_vimeo']['id'] = 'field_vimeo';
  $handler->display->display_options['fields']['field_vimeo']['table'] = 'field_data_field_vimeo';
  $handler->display->display_options['fields']['field_vimeo']['field'] = 'field_vimeo';
  $handler->display->display_options['fields']['field_vimeo']['label'] = '';
  $handler->display->display_options['fields']['field_vimeo']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_vimeo']['alter']['text'] = '<div class="author-vimeo">
<a href="http://vimeo.com/[field_vimeo]">vimeo.com/[field_vimeo]</a>
</div>';
  $handler->display->display_options['fields']['field_vimeo']['element_label_colon'] = FALSE;
  /* Campo: Usuário: YouTube */
  $handler->display->display_options['fields']['field_youtube']['id'] = 'field_youtube';
  $handler->display->display_options['fields']['field_youtube']['table'] = 'field_data_field_youtube';
  $handler->display->display_options['fields']['field_youtube']['field'] = 'field_youtube';
  $handler->display->display_options['fields']['field_youtube']['label'] = '';
  $handler->display->display_options['fields']['field_youtube']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_youtube']['alter']['text'] = '<div class="author-youtube">
<a href="http://youtube.com/[field_youtube]">youtube.com/[field_youtube]</a>
</div>';
  $handler->display->display_options['fields']['field_youtube']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Filtro contextual: Usuário: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Tudo';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['path'] = 'user/%';

  /* Display: Who is logged */
  $handler = $view->new_display('block', 'Who is logged', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Campo: Usuário: Foto */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['empty'] = '<img src="/sites/all/themes/delite/images/avatar-35.jpg">';
  $handler->display->display_options['fields']['picture']['image_style'] = 'related_content_35x35';
  /* Campo: Usuário: Nome real */
  $handler->display->display_options['fields']['field_realname']['id'] = 'field_realname';
  $handler->display->display_options['fields']['field_realname']['table'] = 'field_data_field_realname';
  $handler->display->display_options['fields']['field_realname']['field'] = 'field_realname';
  $handler->display->display_options['fields']['field_realname']['label'] = '';
  $handler->display->display_options['fields']['field_realname']['element_label_colon'] = FALSE;
  /* Campo: Usuário: Link */
  $handler->display->display_options['fields']['view_user']['id'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['table'] = 'users';
  $handler->display->display_options['fields']['view_user']['field'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['label'] = '';
  $handler->display->display_options['fields']['view_user']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_user']['text'] = 'Minha conta';
  /* Campo: Global: Texto personalizado */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="/user/logout">Sair</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Filtro contextual: Usuário: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Tudo';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['block_description'] = 'Who is logged';
  $translatables['usuarios'] = array(
    t('Master'),
    t('Autores'),
    t('mais'),
    t('Aplicar'),
    t('Restaurar'),
    t('Ordenar por'),
    t('Crescente'),
    t('Desc'),
    t('Itens por página'),
    t('- Todos -'),
    t('Deslocamento'),
    t('« início'),
    t('‹ anterior'),
    t('próximo ›'),
    t('fim »'),
    t('<img src="/sites/all/themes/delite/images/avatar-150.jpg">'),
    t('Block'),
    t('Página'),
    t('%1'),
    t('<div class="image-name-patente-user">
  <div class="image-user">[picture]</div>
  <div class="name-user">[field_realname]</div>
</div>'),
    t('<div class="perfil-drupal-org">
<a href="http://drupal.org/user/[field_drupal_org]">drupal.org/user/[field_drupal_org]</a>
</div>'),
    t('<div class="author-facebook">
<a href="http://facebook.com/[field_facebook]">facebook.com/[field_facebook]</a>
</div>'),
    t('<div class="author-gplus">
<a href="https://plus.google.com/[field_google]">plus.google.com/[field_google]</a>
</div>'),
    t('<div class="author-twitter">
<a href="http://twitter.com/[field_twitter]">@[field_twitter]</a>
</div>'),
    t('<div class="author-vimeo">
<a href="http://vimeo.com/[field_vimeo]">vimeo.com/[field_vimeo]</a>
</div>'),
    t('<div class="author-youtube">
<a href="http://youtube.com/[field_youtube]">youtube.com/[field_youtube]</a>
</div>'),
    t('Tudo'),
    t('Who is logged'),
    t('<img src="/sites/all/themes/delite/images/avatar-35.jpg">'),
    t('Minha conta'),
    t('<a href="/user/logout">Sair</a>'),
  );
  $export['usuarios'] = $view;

  $view = new view();
  $view->name = 'view_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'View Search (good)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Busca';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mais';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Restaurar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Crescente';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '7';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '5';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Itens por página';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Todos -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Deslocamento';
  $handler->display->display_options['pager']['options']['tags']['first'] = '«««';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '«';
  $handler->display->display_options['pager']['options']['tags']['next'] = '»';
  $handler->display->display_options['pager']['options']['tags']['last'] = '»»»';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Comportamento quando sem resultados: Global: Área de texto */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p><strong>Eita!</strong></p>
<p>Nós não conseguimos encontrar nada sobre <strong>!1</strong>... :(</p>
<p>Que tal alterar o termo de sua busca?</p>';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = TRUE;
  /* Campo: Conteúdo: Título */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Critério de ordenação: Conteúdo: Data de publicação */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filtro contextual: Buscar: Termos de busca */
  $handler->display->display_options['arguments']['keys']['id'] = 'keys';
  $handler->display->display_options['arguments']['keys']['table'] = 'search_index';
  $handler->display->display_options['arguments']['keys']['field'] = 'keys';
  $handler->display->display_options['arguments']['keys']['default_action'] = 'default';
  $handler->display->display_options['arguments']['keys']['exception']['title'] = 'Tudo';
  $handler->display->display_options['arguments']['keys']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['keys']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['keys']['default_argument_options']['use_alias'] = TRUE;
  $handler->display->display_options['arguments']['keys']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['keys']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['keys']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Conteúdo: Publicado */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Conteúdo: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'curso' => 'curso',
    'evento' => 'evento',
    'podcast' => 'podcast',
    'blog' => 'blog',
    'screencast' => 'screencast',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'search/node/%';
  $translatables['view_search'] = array(
    t('Master'),
    t('Busca'),
    t('mais'),
    t('Aplicar'),
    t('Restaurar'),
    t('Ordenar por'),
    t('Crescente'),
    t('Desc'),
    t('Itens por página'),
    t('- Todos -'),
    t('Deslocamento'),
    t('«««'),
    t('«'),
    t('»'),
    t('»»»'),
    t('<p><strong>Eita!</strong></p>
<p>Nós não conseguimos encontrar nada sobre <strong>!1</strong>... :(</p>
<p>Que tal alterar o termo de sua busca?</p>'),
    t('Tudo'),
    t('Page'),
  );
  $export['view_search'] = $view;

  return $export;
}
