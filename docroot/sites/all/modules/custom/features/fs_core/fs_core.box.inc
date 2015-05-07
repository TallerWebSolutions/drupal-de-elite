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
  $box->delta = 'contact_block';
  $box->plugin_key = 'simple';
  $box->title = 'Contato';
  $box->description = 'Bloco com informações de contato';
  $box->options = array(
    'body' => array(
      'value' => 'Aqui vem as informações de contato.',
      'format' => 'filtered_html',
    ),
  );
  $export['contact_block'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'facebook_likebox';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Facebook Like Box';
  $box->options = array(
    'body' => array(
      'value' => '<iframe src="//www.facebook.com/plugins/likebox.php?href=http%3A%2F%2Fwww.facebook.com%2Fdrupaldeelite&amp;width=260&amp;height=290&amp;colorscheme=light&amp;show_faces=true&amp;border_color=%23ffffff&amp;stream=false&amp;header=false&amp;appId=131612406981819" scrolling="no" frameborder="0" style="border:none; overflow:hidden; width:260px; height:275px;" allowTransparency="true"></iframe>',
      'format' => 'filtered_html',
    ),
    'additional_classes' => '',
  );
  $export['facebook_likebox'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'feed_rss';
  $box->plugin_key = 'simple';
  $box->title = '';
  $box->description = 'Feeds';
  $box->options = array(
    'body' => array(
      'value' => '<div class="feed-block">
<a href="/rss.xml" target="_blank">Geral</a>
<a href="/blog/rss.xml" target="_blank">Blog</a>
<a href="/podcast/rss.xml" target="_blank">Podcast</a>
<a href="/video/rss.xml" target="_blank">Vídeos</a>
</div>',
      'format' => 'filtered_html',
    ),
    'additional_classes' => '',
  );
  $export['feed_rss'] = $box;

  return $export;
}
