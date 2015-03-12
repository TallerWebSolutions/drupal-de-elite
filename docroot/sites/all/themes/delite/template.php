<?php

/*
 * Implements hook_preprocess_page()
 */
function delite_preprocess_page(&$vars) {
	
	// Add js file for contruct ui tab
	if (request_path() == "curso") {
		drupal_add_library ( 'system' , 'ui.tabs' );
	}
}