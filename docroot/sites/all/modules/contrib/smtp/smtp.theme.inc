<?php

/**
 * Themes a table that allows rows and columns to be render arrays. This is used to create a drag and drop table
 * on the administration page.
 * The children of the root element are considered table rows and their children are the table columns.
 *
 * @param vars
 *  Variables passed to the theme function.
 */
function theme_smtp_table(&$vars) {
  $table_element = &$vars['element'];

  $rows = array();
  foreach (element_children($table_element, TRUE) as $row_name) {
    $row_element = &$table_element[$row_name];
    $row = (!empty($row_element['#attributes'])) ? $row_element['#attributes'] : array();

    $row_data = array();
    foreach (element_children($row_element, TRUE) as $col_name) {
      $row_data[] = render($row_element[$col_name]);
    }
    $row['data'] = $row_data;

    $rows[] = $row;
    unset($table_element[$row_name]);
  }
  $table_element['#rows'] = $rows;

  $table_element['#theme'] = 'table';
  return render($table_element);
}

/**
 * Themes a selection criteria as a logical expression (as shown in the administration page's table).
 * Render array structure:
 *  #criteria => The selection criteria (associative array) to be displayed.
 *
 * @param vars
 *  Variables passed to the theme function.
 */
function theme_smtp_selection_criteria(&$vars) {
  $element = &$vars['element'];
  $criteria = &$element['#criteria'];

  $output = '';

  // Module
  if (!empty($criteria['message_module'])) {
    $expression = t('Module') . '=' . $criteria['message_module'];
    $output = '<em>' . check_plain($expression) . '</em>';
  }

  // Key
  if (!empty($criteria['message_key'])) {
    $expression2 = t('Key', array(), array('context' => 'identifier')) . '=' . $criteria['message_key'];
    if ($output) {
      $t_args = array(
        '!expression1' => $output,
        '%expression2' => $expression2,
      );
      $output = t('!expression1 AND %expression2', $t_args);
    }
    else {
      $output = '<em>' . check_plain($expression2) . '</em>';
    }
  }

  // Language
  if (!empty($criteria['message_language'])) {
    $languages = language_list();
    $language_code = $criteria['message_language'];
    $expression2 = t('Language') . '=' . $languages[$language_code]->name;
    if ($output) {
      $t_args = array(
        '!expression1' => $output,
        '%expression2' => $expression2,
      );
      $output = t('!expression1 AND %expression2', $t_args);
    }
    else {
      $output = '<em>' . check_plain($expression2) . '</em>';
    }
  }

  if (empty($output)) {
    $output = '*';
  }

  return $output;
}
