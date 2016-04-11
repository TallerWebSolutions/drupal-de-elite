<?php

/**
 * Implements hook_html_head_alter().
 */
function druelite_html_head_alter(&$head_elements) {
  foreach ($head_elements as &$element) {
    if (isset($element['#attributes']['rel'])
        && in_array($element['#attributes']['rel'], array('canonical', 'shortlink'))
        && drupal_is_front_page()) {
      $element['#attributes']['href'] = '/';
    }
  }
}

/**
 * Implements hook_css_alter().
 */
function druelite_css_alter(&$css) {
  unset($css['modules/poll/poll.css']);

  // Less fallback:
  if (!module_exists('less')) {
    foreach ($css as &$file) {
      if ($file['type'] == 'file' && substr($file['data'], -5) == '.less') {
        $file['data'] = substr($file['data'], 0, -5) . '.css';
      }
    }
  }
}

/**
 * Preprocesses variables for page.tpl.php.
 */
function druelite_preprocess_page(&$vars) {
//  dpm($vars); exit;
  $vars['header_attributes'] = '';
  $page = &$vars['page'];

  if ($page['header_bg']) {
    $children = element_children($page['header_bg']);
    $delta = reset($children);
    $block = $page['header_bg'][$delta]['#block'];
    if ($block->region == 'header_bg' && $block->module == 'imageblock' && module_exists('imageblock')) {
      if ($img = imageblock_get_file($block->delta)) {
        $src = file_create_url($img->uri);
        $vars['header_attributes'] = sprintf(' style="background-image: url(%s)"', $src);
      }
    }
  }
}

/**
 * Processes variables for page.tpl.php.
 */
function druelite_process_page(&$vars) {
//  dpm($vars); exit;
  $page = &$vars['page'];

  if ($vars['is_front'] && !$vars['title']) {
    $vars['title'] = $vars['site_name'];
  }
}

/**
 * Preprocesses variables for region.tpl.php.
 */
function druelite_preprocess_region(&$vars) {
//  dpm($vars['region']); exit;
  $vars['block_count'] = count(element_children($vars['elements']));
}

/**
 * Preprocesses variables for block.tpl.php.
 */
function druelite_preprocess_block(&$vars) {
  $block = &$vars['block'];
  
//  if ($block->region == 'sidebar_second' && $block->module == 'boxes') {
//    dpm($block);
//    $vars['classes_array'] = array('panel', 'panel-primary');
//  }
  if ($block->region == 'header' && $block->module == 'imageblock' && module_exists('imageblock')) {
    if ($img = imageblock_get_file($block->delta)) {
      $src = file_create_url($img->uri);
      $vars['attributes_array']['style'] = sprintf('background-image: url(%s)', $src);
    }
  }
  if ($block->region == 'footer' && $block->module == 'menu' && $block->delta == 'menu-footer-sitemap') {
    $vars['classes_array'][] = 'row';
  }
}

/**
 * Overrides theme_menu_tree() for menu_footer_sitemap.
 */
function druelite_menu_tree__menu_footer_sitemap($vars) {
  return '<ul class="list-unstyled">' . $vars['tree'] . '</ul>';
}

/**
 * Overrides theme_menu_link() for menu_footer_sitemap.
 */
function druelite_menu_link__menu_footer_sitemap($vars) {
  $element = $vars['element'];

  $sub_menu = $element['#below'] ? drupal_render($element['#below']) : '';
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);

  if ($element['#original_link']['depth'] == 1) {
    $element['#attributes']['class'][] = 'root col-xs-6 col-sm-4 col-md-2';
  }
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/**
 * Overrides theme_system_powered_by().
 */
// function druelite_system_powered_by() {
//   return '© ' . date('Y') . ' <a href="' . base_path() . '">' . variable_get('site_name') . '</a>. ' .
//     theme_system_powered_by() .
//     (module_exists('atoms') ? ', <a href="http://drupal.tonystar.me/atoms">Atoms</a>' : '') .
//     ' ' . t('and') . ' <a href="http://drupal.tonystar.me/druelite">druelite</a>.';
// }

/**
 * Preprocesses variables for poll-bar.tpl.php.
 */
function druelite_preprocess_poll_bar(&$vars) {
  $vars['theme_hook_suggestions'] = array('poll_bar');
}

/**
 * Preprocesses variables for theme_item_list().
 */
function druelite_preprocess_item_list(&$vars) {
  $vars['attributes']['class'][] = 'list-unstyled';
}

/**
 * Preprocesses variables for theme_links().
 */
function druelite_preprocess_links(&$vars) {
//  dpm($vars);
  $vars['attributes']['class'][] = 'list-unstyled';
  $vars['links']['node-readmore']['attributes']['class'] = array('btn', 'btn-danger');
  $vars['links']['calendar_link']['attributes']['class'] = array('btn', 'btn-danger');
  $vars['links']['disqus_comments_num']['attributes']['class'] = array('btn', 'btn-danger');
}

/**
 * Implements hook_preprocess_field()
 */
function druelite_preprocess_field(&$vars) {
//  dpm($vars);
  if ($vars['element']['#field_name'] == 'field_tags') {
    array_walk($vars['items'], function(&$el) {
      $el['#options']['attributes']['class'] = array('btn', 'btn-default', 'btn-xs');
      }
    );
  }
  if (($vars['element']['#field_name'] == 'field_video') || ($vars['element']['#field_name'] == 'field_video_auth')) {
    array_walk($vars['items'], function(&$el) {
      $el['file']['#options']['attributes']['class'] = array('embed-responsive', 'embed-responsive-16by9');
      }
    );
  }
}

function druelite_form_views_exposed_form_alter(&$form, &$form_state) {
  $form['submit']['#value'] = '<i class="glyphicon glyphicon-search"></i>';
//dpm($form);
}

function druelite_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id = 'contato-entityform-edit-form') {
//    dpm($form);
    $form['actions']['submit']['#attributes']['class'] = array('btn-xlw', 'btn-lg');
//    $form['field_realname']['#attributes']['class'] = array('form-item');
  }
}

function druelite_form_element($variables) {
  $element = $variables['element'];
//  dpm($element);
  return theme_form_element($variables);
}

function druelite_views_simple_pager($vars) {
  global $pager_page_array, $pager_total;

  $tags = $vars['tags'];
  $element = $vars['element'];
  $parameters = $vars['parameters'];
  $options = $vars['options'];
  
  $prev_label = (!empty($options['prev_label'])) ? $options['prev_label'] : 'previous';
  $next_label = (!empty($options['next_label'])) ? $options['next_label'] : 'next';

  // Yes, I realize that calling t() on user-entered content is a general no-no, but we might get lucky and pick up something like "older" or "newer" from the translation tables  
  $li_previous = theme('pager_previous', array('text' => (isset($tags[1]) ? $tags[1] : t($prev_label)), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  $li_next = theme('pager_next', array('text' => (isset($tags[3]) ? $tags[3] : t($next_label)), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));

  if ($pager_total[$element] > 1) {
    if ($li_previous) {
      $items[] = array(
        'class' => array('btn', 'btn-primary', 'btn-lg', 'previous'),
        'data' => $li_previous,
      );
    }
    if ($li_next) {
      $items[] = array(
        'class' => array('btn', 'btn-primary', 'btn-lg', 'next'),
        'data' => $li_next,
      );
    }
    
    // See if the reverse_links option is set
    if ($options['reverse_links']) {
      $items = array_reverse($items);
    }
    
    return theme('item_list', array(
      'items' => $items,
      'attributes' => array('class' => array('views-pager')),
    ));
  }
}