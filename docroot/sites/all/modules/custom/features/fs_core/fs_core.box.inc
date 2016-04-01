<?php
/**
 * @file
 * fs_core.box.inc
 */

/**
 * Implements hook_default_box().
 */
function fs_core_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'facebook_widget';
  $box->plugin_key = 'simple';
  $box->title = '<none>';
  $box->description = 'Facebook widget';
  $box->options = array(
    'body' => array(
      'value' => '<div id="container" style="width:100%;">  
<div class="fb-page" data-href="https://www.facebook.com/drupaldeelite" data-small-header="false" data-adapt-container-width="true" data-hide-cover="false" data-show-facepile="true"><div class="fb-xfbml-parse-ignore"><blockquote cite="https://www.facebook.com/drupaldeelite"><a href="https://www.facebook.com/drupaldeelite">Drupal de Elite</a></blockquote></div></div>
</div>',
      'format' => 'html_puro',
    ),
    'additional_classes' => '',
  );
  $export['facebook_widget'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'twitter_widget';
  $box->plugin_key = 'simple';
  $box->title = '<none>';
  $box->description = 'Twitter widget';
  $box->options = array(
    'body' => array(
      'value' => '<a class="twitter-timeline"
  href="https://twitter.com/DrupalDeElite"
  data-widget-id="704120359059116033"
  data-chrome="nofooter noborders noscrollbar transparent"
  data-tweet-limit="2">
@DrupalDeElite
</a>
<script>!function(d,s,id){var js,fjs=d.getElementsByTagName(s)[0],p=/^http:/.test(d.location)?\'http\':\'https\';if(!d.getElementById(id)){js=d.createElement(s);js.id=id;js.src=p+"://platform.twitter.com/widgets.js";fjs.parentNode.insertBefore(js,fjs);}}(document,"script","twitter-wjs");</script>
          ',
      'format' => 'html_puro',
    ),
    'additional_classes' => '',
  );
  $export['twitter_widget'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'youtube_subscribe';
  $box->plugin_key = 'simple';
  $box->title = 'Siga-nos';
  $box->description = 'Youtube widget';
  $box->options = array(
    'body' => array(
      'value' => '<div class="g-ytsubscribe" data-channelid="UCRGragIHWUm4vxVj8XCwKyQ" data-layout="full" data-count="default" data-onytevent="onYtEvent"></div>',
      'format' => 'html_puro',
    ),
    'additional_classes' => '',
  );
  $export['youtube_subscribe'] = $box;

  return $export;
}
