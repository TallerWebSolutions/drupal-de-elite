<?php
/**
 * @file
 * fs_cursos.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function fs_cursos_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'cursos';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Cursos';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Cursos';
  $handler->display->display_options['use_ajax'] = TRUE;
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
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
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
    'field_image' => 'field_image',
    'field_description' => 'field_description',
  );
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
    'trim_length' => '200',
  );
  /* Campo: Conteúdo: Carga horária */
  $handler->display->display_options['fields']['field_carga_horaria']['id'] = 'field_carga_horaria';
  $handler->display->display_options['fields']['field_carga_horaria']['table'] = 'field_data_field_carga_horaria';
  $handler->display->display_options['fields']['field_carga_horaria']['field'] = 'field_carga_horaria';
  $handler->display->display_options['fields']['field_carga_horaria']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_carga_horaria']['settings'] = array(
    'trim_length' => '10',
  );
  /* Campo: Conteúdo: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Saiba mais...';
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
  /* Filter criterion: Conteúdo: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'curso' => 'curso',
  );
  /* Filter criterion: Conteúdo: Nível (field_nivel) */
  $handler->display->display_options['filters']['field_nivel_value']['id'] = 'field_nivel_value';
  $handler->display->display_options['filters']['field_nivel_value']['table'] = 'field_data_field_nivel';
  $handler->display->display_options['filters']['field_nivel_value']['field'] = 'field_nivel_value';
  $handler->display->display_options['filters']['field_nivel_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_nivel_value']['expose']['operator_id'] = 'field_nivel_value_op';
  $handler->display->display_options['filters']['field_nivel_value']['expose']['label'] = 'Nível (field_nivel)';
  $handler->display->display_options['filters']['field_nivel_value']['expose']['operator'] = 'field_nivel_value_op';
  $handler->display->display_options['filters']['field_nivel_value']['expose']['identifier'] = 'field_nivel_value';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Iniciante';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Intermediario';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
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
    'curso' => 'curso',
  );
  /* Filter criterion: Conteúdo: Nível (field_nivel) */
  $handler->display->display_options['filters']['field_nivel_value']['id'] = 'field_nivel_value';
  $handler->display->display_options['filters']['field_nivel_value']['table'] = 'field_data_field_nivel';
  $handler->display->display_options['filters']['field_nivel_value']['field'] = 'field_nivel_value';
  $handler->display->display_options['filters']['field_nivel_value']['value'] = array(
    2 => '2',
  );
  $handler->display->display_options['filters']['field_nivel_value']['expose']['operator_id'] = 'field_nivel_value_op';
  $handler->display->display_options['filters']['field_nivel_value']['expose']['label'] = 'Nível (field_nivel)';
  $handler->display->display_options['filters']['field_nivel_value']['expose']['operator'] = 'field_nivel_value_op';
  $handler->display->display_options['filters']['field_nivel_value']['expose']['identifier'] = 'field_nivel_value';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Avançado';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
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
    'curso' => 'curso',
  );
  /* Filter criterion: Conteúdo: Nível (field_nivel) */
  $handler->display->display_options['filters']['field_nivel_value']['id'] = 'field_nivel_value';
  $handler->display->display_options['filters']['field_nivel_value']['table'] = 'field_data_field_nivel';
  $handler->display->display_options['filters']['field_nivel_value']['field'] = 'field_nivel_value';
  $handler->display->display_options['filters']['field_nivel_value']['value'] = array(
    3 => '3',
  );
  $handler->display->display_options['filters']['field_nivel_value']['expose']['operator_id'] = 'field_nivel_value_op';
  $handler->display->display_options['filters']['field_nivel_value']['expose']['label'] = 'Nível (field_nivel)';
  $handler->display->display_options['filters']['field_nivel_value']['expose']['operator'] = 'field_nivel_value_op';
  $handler->display->display_options['filters']['field_nivel_value']['expose']['identifier'] = 'field_nivel_value';
  $translatables['cursos'] = array(
    t('Master'),
    t('Cursos'),
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
    t('Carga horária'),
    t('Saiba mais...'),
    t('Nível (field_nivel)'),
    t('Block'),
    t('Iniciante'),
    t('Intermediario'),
    t('Avançado'),
  );
  $export['cursos'] = $view;

  return $export;
}
