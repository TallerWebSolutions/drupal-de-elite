<?php
/**
 * @file
 * Chatroll Live Chat platform extension
 * License: GPL v2 - http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
 */

require_once 'chatroll.php';

/**
 * Drupal Chatroll module extension
 * License: GPL v2 - http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
 */
class DrupalChatroll extends Chatroll {
  // Default width/height.
  public $width = '450';
  public $height = '350';
  public $showlink = 1;

  /**
   * Override: Append width/height and SSO params
   */
  public function appendPlatformDefaultAttr($attr) {
    $attr['platform'] = 'drupal';

    if ($this->showlink) {
      $attr['linkurl'] = '/solutions/drupal-chat-module';
      $attr['linktxt'] = 'Drupal chat';
    }
    else {
      $attr['linkurl'] = '';
      $attr['linktxt'] = '';
    }

    // Values set via module params.
    $attr['height'] = $this->height;
    $attr['width'] = $this->width;

    // Append User info for SSO integration.
    global $user;
    if ($user->uid) {
      $attr['uid'] = $user->uid;
      $attr['uname'] = $user->name;
    }

    // Moderation permission managed in site Permissions settings.
    $attr['ismod'] = user_access('moderate chatroll') ? 1 : 0;

    // User picture may be enabled in site User Settings.
    if (!empty($user->picture)) {
      global $base_url;
      $attr['upic'] = $base_url . '/' . $user->picture;
    }

    // Note: Add your custom profile URL here.
    // $attr['ulink]' = '';.
    return $attr;
  }
}
