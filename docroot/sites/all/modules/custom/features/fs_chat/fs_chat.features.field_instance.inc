<?php
/**
 * @file
 * fs_chat.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function fs_chat_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-tribune-field_chat'
  $field_instances['node-tribune-field_chat'] = array(
    'bundle' => 'tribune',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_chat',
    'label' => 'Chat para',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Chat para');

  return $field_instances;
}
