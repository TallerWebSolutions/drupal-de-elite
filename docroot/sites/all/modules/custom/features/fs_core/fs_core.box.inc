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
  $box->delta = 'home_presentation';
  $box->plugin_key = 'simple';
  $box->title = '<none>';
  $box->description = 'Apresentação da home';
  $box->options = array(
    'body' => array(
      'value' => '<p>[[{"fid":"225","view_mode":"full","fields":{"format":"full"},"type":"media","link_text":"Drupal Zero - Como fazer um blog ou site institucional sem saber programar!","attributes":{"class":"file media-element file-full"}}]]</p>
',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['home_presentation'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'quem_somos';
  $box->plugin_key = 'simple';
  $box->title = '<none>';
  $box->description = 'Quem somos home';
  $box->options = array(
    'body' => array(
      'value' => '<p>Curabitur gravida, leo eu eleifend lacinia, enim elit eleifend augue, vel aliquam mauris sapien sed metus. Proin tincidunt erat ac egestas ultrices. Aenean aliquet quam vel maximus bibendum. Morbi eu tortor ac enim elementum iaculis. Sed mollis diam eu porta pellentesque. In ut molestie nibh.</p>

<p>Nulla congue feugiat mollis. Donec efficitur justo velit, sed commodo nisl ornare ut. Nulla consectetur magna at turpis ullamcorper, et aliquet elit auctor. Integer rutrum ipsum arcu, iaculis consectetur urna venenatis sed. Morbi pretium orci et orci accumsan, quis congue elit malesuada. Pellentesque nec odio ut diam congue imperdiet ut eu nisi.</p>
',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['quem_somos'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'rodape';
  $box->plugin_key = 'simple';
  $box->title = '<none>';
  $box->description = 'Rodapé';
  $box->options = array(
    'body' => array(
      'value' => '<h2>Cursos e treinamentos Drupal</h2>

<p><a class="btn btn-primary" href="/curso">Eu quero!</a></p>

<p style="text-align: right;">Espaço dedicado ao estudo do DRUPAL desenvolvido com amor.</p>
',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['rodape'] = $box;

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
