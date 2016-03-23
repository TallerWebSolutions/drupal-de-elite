<?php
/**
 * @file
 * fs_cursos.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function fs_cursos_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create curso content'.
  $permissions['create curso content'] = array(
    'name' => 'create curso content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any curso content'.
  $permissions['delete any curso content'] = array(
    'name' => 'delete any curso content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own curso content'.
  $permissions['delete own curso content'] = array(
    'name' => 'delete own curso content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any curso content'.
  $permissions['edit any curso content'] = array(
    'name' => 'edit any curso content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own curso content'.
  $permissions['edit own curso content'] = array(
    'name' => 'edit own curso content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
