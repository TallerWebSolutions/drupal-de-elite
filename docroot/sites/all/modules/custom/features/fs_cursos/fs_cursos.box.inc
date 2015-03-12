<?php
/**
 * @file
 * fs_cursos.box.inc
 */

/**
 * Implements hook_default_box().
 */
function fs_cursos_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'curso_chamada';
  $box->plugin_key = 'simple';
  $box->title = '<none>';
  $box->description = 'Chamada para cursos';
  $box->options = array(
    'body' => array(
      'value' => 'Você pode ser um gerente de TI querendo capacitar seu time de Drupal, um desenvolvedor web querendo aprender a criar aplicações com Drupal, um redator, editor de revista online, blogueiro... a gente ensina como suprir as necessidades e resolver as reais situações com Drupal.',
      'format' => 'filtered_html',
    ),
  );
  $export['curso_chamada'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'curso_contato';
  $box->plugin_key = 'simple';
  $box->title = 'Peça treinamento!';
  $box->description = 'Contato para cursos';
  $box->options = array(
    'body' => array(
      'value' => 'A partir da alta procura de profissionais Drupal e da demanda de qualificação, um grupo de pessoas apaixonadas por desenvolvimento web e especificamente por Drupal, criou o Drupal de Elite, no intuito de compartilhar conhecimento, formar desenvolvedores certificados, fomentar o Drupal no Brasil e aumentar o nível das habilidades dos profissionais brasileiros.

<a href="/contato">Peça agora seu treinamento Drupal</a>',
      'format' => 'filtered_html',
    ),
    'additional_classes' => '',
  );
  $export['curso_contato'] = $box;

  return $export;
}
