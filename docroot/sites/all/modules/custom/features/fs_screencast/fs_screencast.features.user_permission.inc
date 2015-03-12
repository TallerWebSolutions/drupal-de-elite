<?php
/**
 * @file
 * fs_screencast.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function fs_screencast_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create screencast content'.
  $permissions['create screencast content'] = array(
    'name' => 'create screencast content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any screencast content'.
  $permissions['delete any screencast content'] = array(
    'name' => 'delete any screencast content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own screencast content'.
  $permissions['delete own screencast content'] = array(
    'name' => 'delete own screencast content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any screencast content'.
  $permissions['edit any screencast content'] = array(
    'name' => 'edit any screencast content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own screencast content'.
  $permissions['edit own screencast content'] = array(
    'name' => 'edit own screencast content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
