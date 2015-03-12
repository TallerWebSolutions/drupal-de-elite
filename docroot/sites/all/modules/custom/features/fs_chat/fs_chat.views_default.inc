<?php
/**
 * @file
 * fs_chat.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function fs_chat_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'chat';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Chat';
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
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Aplicar';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Restaurar';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Ordenar por';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Crescente';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'full';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Relação: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_chat_target_id']['id'] = 'field_chat_target_id';
  $handler->display->display_options['relationships']['field_chat_target_id']['table'] = 'field_data_field_chat';
  $handler->display->display_options['relationships']['field_chat_target_id']['field'] = 'field_chat_target_id';
  $handler->display->display_options['relationships']['field_chat_target_id']['label'] = 'field_chat';
  $handler->display->display_options['relationships']['field_chat_target_id']['required'] = TRUE;
  /* Campo: Conteúdo: Título */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Filtro contextual: Conteúdo: Chat para (field_chat) */
  $handler->display->display_options['arguments']['field_chat_target_id']['id'] = 'field_chat_target_id';
  $handler->display->display_options['arguments']['field_chat_target_id']['table'] = 'field_data_field_chat';
  $handler->display->display_options['arguments']['field_chat_target_id']['field'] = 'field_chat_target_id';
  $handler->display->display_options['arguments']['field_chat_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_chat_target_id']['exception']['title'] = 'Tudo';
  $handler->display->display_options['arguments']['field_chat_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_chat_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_chat_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_chat_target_id']['summary_options']['items_per_page'] = '25';
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
    'tribune' => 'tribune',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $translatables['chat'] = array(
    t('Master'),
    t('mais'),
    t('Aplicar'),
    t('Restaurar'),
    t('Ordenar por'),
    t('Crescente'),
    t('Desc'),
    t('field_chat'),
    t('Tudo'),
    t('Block'),
  );
  $export['chat'] = $view;

  return $export;
}
