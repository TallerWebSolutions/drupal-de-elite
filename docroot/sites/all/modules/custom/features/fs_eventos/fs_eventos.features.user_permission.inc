<?php
/**
 * @file
 * fs_eventos.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function fs_eventos_user_default_permissions() {
  $permissions = array();

  // Exported permission: create field_video_auth.
  $permissions['create field_video_auth'] = array(
    'name' => 'create field_video_auth',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_video_auth.
  $permissions['edit field_video_auth'] = array(
    'name' => 'edit field_video_auth',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_video_auth.
  $permissions['edit own field_video_auth'] = array(
    'name' => 'edit own field_video_auth',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_video_auth.
  $permissions['view field_video_auth'] = array(
    'name' => 'view field_video_auth',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_video_auth.
  $permissions['view own field_video_auth'] = array(
    'name' => 'view own field_video_auth',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
