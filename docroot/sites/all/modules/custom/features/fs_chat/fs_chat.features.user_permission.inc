<?php
/**
 * @file
 * fs_chat.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function fs_chat_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create tribune content'.
  $permissions['create tribune content'] = array(
    'name' => 'create tribune content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any tribune content'.
  $permissions['delete any tribune content'] = array(
    'name' => 'delete any tribune content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own tribune content'.
  $permissions['delete own tribune content'] = array(
    'name' => 'delete own tribune content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any tribune content'.
  $permissions['edit any tribune content'] = array(
    'name' => 'edit any tribune content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own tribune content'.
  $permissions['edit own tribune content'] = array(
    'name' => 'edit own tribune content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
