<?php
/**
 * @file
 * fs_podcast.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function fs_podcast_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create podcast content'.
  $permissions['create podcast content'] = array(
    'name' => 'create podcast content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any podcast content'.
  $permissions['delete any podcast content'] = array(
    'name' => 'delete any podcast content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own podcast content'.
  $permissions['delete own podcast content'] = array(
    'name' => 'delete own podcast content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any podcast content'.
  $permissions['edit any podcast content'] = array(
    'name' => 'edit any podcast content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own podcast content'.
  $permissions['edit own podcast content'] = array(
    'name' => 'edit own podcast content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
