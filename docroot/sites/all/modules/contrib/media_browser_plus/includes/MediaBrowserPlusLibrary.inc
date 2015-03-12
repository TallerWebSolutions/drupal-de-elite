<?php

class MediaBrowserPlusLibrary extends MediaBrowserLibrary {

  function view() {
    $types = isset($this->params['types']) ? $this->params['types'] : array();
    $multiselect = isset($this->params['multiselect']) ? $this->params['multiselect'] : FALSE;

    // Get plugin form.
    $upload_form = drupal_get_form('media_browser_plus_library_browser', $multiselect, $types);
    $upload_form['#title'] = t('Library Plus');

    $upload_form['admin']['#markup'] .= l(t('Cancel'), '', array(
      'attributes' => array('class' => array('button', 'fake-cancel', $this->info['name']))
    ));

    return $upload_form;
  }

}
