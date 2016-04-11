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
  $view->name = 'courses';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Cursos';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Iniciante';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'mais';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Restaurar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Crescente';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'panel panel-primary';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_carga_horaria' => 'field_carga_horaria',
  );
  /* Campo: Conteúdo: Título */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
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
  /* Campo: Conteúdo: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_class'] = 'btn btn-primary btn-sm';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'Saiba mais...';
  /* Critério de ordenação: Conteúdo: Título */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Critério de filtragem: Conteúdo: Publicado */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Critério de filtragem: Conteúdo: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'curso' => 'curso',
  );
  /* Critério de filtragem: Conteúdo: Nível (field_nivel) */
  $handler->display->display_options['filters']['field_nivel_value']['id'] = 'field_nivel_value';
  $handler->display->display_options['filters']['field_nivel_value']['table'] = 'field_data_field_nivel';
  $handler->display->display_options['filters']['field_nivel_value']['field'] = 'field_nivel_value';
  $handler->display->display_options['filters']['field_nivel_value']['value'] = array(
    1 => '1',
  );

  /* Display: Iniciante */
  $handler = $view->new_display('block', 'Iniciante', 'block');

  /* Display: Intermediário */
  $handler = $view->new_display('block', 'Intermediário', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Intermediário';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Critério de filtragem: Conteúdo: Publicado */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Critério de filtragem: Conteúdo: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'curso' => 'curso',
  );
  /* Critério de filtragem: Conteúdo: Nível (field_nivel) */
  $handler->display->display_options['filters']['field_nivel_value']['id'] = 'field_nivel_value';
  $handler->display->display_options['filters']['field_nivel_value']['table'] = 'field_data_field_nivel';
  $handler->display->display_options['filters']['field_nivel_value']['field'] = 'field_nivel_value';
  $handler->display->display_options['filters']['field_nivel_value']['value'] = array(
    2 => '2',
  );

  /* Display: Avançado */
  $handler = $view->new_display('block', 'Avançado', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Avançado';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Critério de filtragem: Conteúdo: Publicado */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Critério de filtragem: Conteúdo: Tipo */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'curso' => 'curso',
  );
  /* Critério de filtragem: Conteúdo: Nível (field_nivel) */
  $handler->display->display_options['filters']['field_nivel_value']['id'] = 'field_nivel_value';
  $handler->display->display_options['filters']['field_nivel_value']['table'] = 'field_data_field_nivel';
  $handler->display->display_options['filters']['field_nivel_value']['field'] = 'field_nivel_value';
  $handler->display->display_options['filters']['field_nivel_value']['value'] = array(
    3 => '3',
  );
  $translatables['courses'] = array(
    t('Master'),
    t('Iniciante'),
    t('mais'),
    t('Aplicar'),
    t('Restaurar'),
    t('Ordenar por'),
    t('Crescente'),
    t('Desc'),
    t('Carga horária'),
    t('Saiba mais...'),
    t('Intermediário'),
    t('Avançado'),
  );
  $export['courses'] = $view;

  return $export;
}
