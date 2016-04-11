<?php
/**
 * @file
 * fs_core.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function fs_core_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "boxes" && $api == "box") {
    return array("version" => "1");
  }
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
  if ($module == "file_entity" && $api == "file_type") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function fs_core_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_entityform_type().
 */
function fs_core_default_entityform_type() {
  $items = array();
  $items['contato'] = entity_import('entityform_type', '{
    "type" : "contato",
    "label" : "Contato",
    "data" : {
      "draftable" : 0,
      "draft_redirect_path" : "",
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "html_puro" },
      "submit_button_text" : "",
      "submit_confirm_msg" : "Obrigado por entrar em contato conosco! Responderemos em breve.",
      "your_submissions" : "",
      "disallow_resubmit_msg" : "",
      "delete_confirm_msg" : "",
      "page_title_view" : "",
      "preview_page" : 0,
      "submission_page_title" : "Contato",
      "submission_text" : {
        "value" : "\\u003Cp\\u003ESua mensagem foi enviada e responderemos em breve!\\u003C\\/p\\u003E\\r\\n",
        "format" : "full_html"
      },
      "submission_show_submitted" : 0,
      "submissions_view" : "default",
      "user_submissions_view" : "default",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : { "1" : "1", "2" : "2", "3" : "3" },
      "resubmit_action" : "new",
      "redirect_path" : "contato",
      "instruction_pre" : { "value" : "", "format" : "html_puro" }
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : { "submit" : {
        "source" : "eform\\/submit\\/contato",
        "alias" : "contato",
        "language" : "und"
      }
    }
  }');
  return $items;
}

/**
 * Implements hook_node_info().
 */
function fs_core_node_info() {
  $items = array(
    'page' => array(
      'name' => t('Página'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Título'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function fs_core_default_search_api_index() {
  $items = array();
  $items['default_node_index'] = entity_import('search_api_index', '{
    "name" : "Default node index",
    "machine_name" : "default_node_index",
    "description" : "An automatically created search index for indexing node data. Might be configured to specific needs.",
    "server" : "database_server",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [] },
      "index_directly" : 1,
      "cron_limit" : "50",
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-50",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "-49", "settings" : [] },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "-48", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "-47",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "-46", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "-45", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "-44", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "-43", "settings" : { "fields" : [] } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "type" : true,
              "title" : true,
              "url" : true,
              "status" : true,
              "promote" : true,
              "sticky" : true,
              "created" : true,
              "changed" : true,
              "author" : true,
              "field_tags" : true,
              "field_palestrante" : true,
              "field_nivel" : true,
              "field_tipo_curso" : true,
              "search_api_language" : true,
              "search_api_access_node" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_audio:file" : true,
              "field_video:file" : true,
              "field_video_auth:file" : true,
              "field_audio:file:name" : true,
              "field_audio:file:field_file_image_alt_text" : true,
              "field_audio:file:field_file_image_title_text" : true,
              "field_video:file:name" : true,
              "field_video:file:field_file_image_alt_text" : true,
              "field_video:file:field_file_image_title_text" : true,
              "field_video_auth:file:name" : true,
              "field_video_auth:file:field_file_image_alt_text" : true,
              "field_video_auth:file:field_file_image_title_text" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_tags" : true,
              "body:value" : true,
              "body:summary" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 1,
          "weight" : "15",
          "settings" : { "fields" : {
              "type" : true,
              "title" : true,
              "url" : true,
              "status" : true,
              "promote" : true,
              "sticky" : true,
              "created" : true,
              "changed" : true,
              "author" : true,
              "field_tags" : true,
              "field_palestrante" : true,
              "field_nivel" : true,
              "field_tipo_curso" : true,
              "search_api_language" : true,
              "search_api_access_node" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_audio:file" : true,
              "field_video:file" : true,
              "field_video_auth:file" : true,
              "field_audio:file:name" : true,
              "field_audio:file:field_file_image_alt_text" : true,
              "field_audio:file:field_file_image_title_text" : true,
              "field_video:file:name" : true,
              "field_video:file:field_file_image_alt_text" : true,
              "field_video:file:field_file_image_title_text" : true,
              "field_video_auth:file:name" : true,
              "field_video_auth:file:field_file_image_alt_text" : true,
              "field_video_auth:file:field_file_image_title_text" : true
            }
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "body:value" : true,
              "body:summary" : true,
              "field_audio:file:name" : true,
              "field_audio:file:field_file_image_alt_text" : true,
              "field_audio:file:field_file_image_title_text" : true,
              "field_video:file:name" : true,
              "field_video:file:field_file_image_alt_text" : true,
              "field_video:file:field_file_image_title_text" : true,
              "field_video_auth:file:name" : true,
              "field_video_auth:file:field_file_image_alt_text" : true,
              "field_video_auth:file:field_file_image_title_text" : true
            },
            "spaces" : "[^\\\\p{L}\\\\p{N}]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 1,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      },
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "body:summary" : { "type" : "text", "boost" : "3.0" },
        "body:value" : { "type" : "text", "boost" : "3.0" },
        "changed" : { "type" : "date" },
        "created" : { "type" : "date" },
        "field_audio:file" : { "type" : "integer", "entity_type" : "file" },
        "field_audio:file:field_file_image_alt_text" : { "type" : "text" },
        "field_audio:file:field_file_image_title_text" : { "type" : "text" },
        "field_audio:file:name" : { "type" : "text" },
        "field_nivel" : { "type" : "string" },
        "field_palestrante" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "user" },
        "field_tags" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_tipo_curso" : { "type" : "list\\u003Cstring\\u003E" },
        "field_video:file" : { "type" : "integer", "entity_type" : "file" },
        "field_video:file:field_file_image_alt_text" : { "type" : "text" },
        "field_video:file:field_file_image_title_text" : { "type" : "text" },
        "field_video:file:name" : { "type" : "text" },
        "field_video_auth:file" : { "type" : "integer", "entity_type" : "file" },
        "field_video_auth:file:field_file_image_alt_text" : { "type" : "text" },
        "field_video_auth:file:field_file_image_title_text" : { "type" : "text" },
        "field_video_auth:file:name" : { "type" : "text" },
        "promote" : { "type" : "boolean" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_language" : { "type" : "string" },
        "status" : { "type" : "integer" },
        "sticky" : { "type" : "boolean" },
        "title" : { "type" : "text", "boost" : "5.0" },
        "type" : { "type" : "string" },
        "url" : { "type" : "uri" }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function fs_core_default_search_api_server() {
  $items = array();
  $items['database_server'] = entity_import('search_api_server', '{
    "name" : "Database server",
    "machine_name" : "database_server",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "3",
      "partial_matches" : 1,
      "indexes" : { "default_node_index" : {
          "type" : {
            "table" : "search_api_db_default_node_index",
            "column" : "type",
            "type" : "string",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_default_node_index_text_1",
            "type" : "text",
            "boost" : "5.0",
            "column" : "title"
          },
          "promote" : {
            "table" : "search_api_db_default_node_index",
            "column" : "promote",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "sticky" : {
            "table" : "search_api_db_default_node_index",
            "column" : "sticky",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_default_node_index",
            "column" : "created",
            "type" : "date",
            "boost" : "1.0"
          },
          "changed" : {
            "table" : "search_api_db_default_node_index",
            "column" : "changed",
            "type" : "date",
            "boost" : "1.0"
          },
          "author" : {
            "table" : "search_api_db_default_node_index",
            "column" : "author",
            "type" : "integer",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_default_node_index",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "body:value" : {
            "table" : "search_api_db_default_node_index_text_1",
            "type" : "text",
            "boost" : "3.0",
            "column" : "body_value"
          },
          "url" : {
            "table" : "search_api_db_default_node_index",
            "column" : "url",
            "type" : "uri",
            "boost" : "1.0"
          },
          "search_api_access_node" : {
            "table" : "search_api_db_default_node_index_search_api_access_node",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "field_tags" : {
            "table" : "search_api_db_default_node_index_field_tags",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "status" : {
            "table" : "search_api_db_default_node_index",
            "column" : "status",
            "type" : "integer",
            "boost" : "1.0"
          },
          "body:summary" : {
            "table" : "search_api_db_default_node_index_text_1",
            "type" : "text",
            "boost" : "3.0",
            "column" : "body_summary"
          },
          "field_palestrante" : {
            "table" : "search_api_db_default_node_index_field_palestrante",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_nivel" : {
            "table" : "search_api_db_default_node_index",
            "column" : "field_nivel",
            "type" : "string",
            "boost" : "1.0"
          },
          "field_tipo_curso" : {
            "table" : "search_api_db_default_node_index_field_tipo_curso",
            "column" : "value",
            "type" : "list\\u003Cstring\\u003E",
            "boost" : "1.0"
          },
          "field_audio:file" : {
            "table" : "search_api_db_default_node_index",
            "column" : "field_audio_file",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_video:file" : {
            "table" : "search_api_db_default_node_index",
            "column" : "field_video_file",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_video_auth:file" : {
            "table" : "search_api_db_default_node_index",
            "column" : "field_video_auth_file",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_audio:file:name" : {
            "table" : "search_api_db_default_node_index_text_1",
            "type" : "text",
            "boost" : "1.0",
            "column" : "field_audio_file_name"
          },
          "field_audio:file:field_file_image_alt_text" : {
            "table" : "search_api_db_default_node_index_text_1",
            "type" : "text",
            "boost" : "1.0",
            "column" : "field_audio_file_field_file_image_alt_text"
          },
          "field_audio:file:field_file_image_title_text" : {
            "table" : "search_api_db_default_node_index_text_1",
            "type" : "text",
            "boost" : "1.0",
            "column" : "field_audio_file_field_file_image_title_text"
          },
          "field_video:file:name" : {
            "table" : "search_api_db_default_node_index_text_1",
            "type" : "text",
            "boost" : "1.0",
            "column" : "field_video_file_name"
          },
          "field_video:file:field_file_image_alt_text" : {
            "table" : "search_api_db_default_node_index_text_1",
            "type" : "text",
            "boost" : "1.0",
            "column" : "field_video_file_field_file_image_alt_text"
          },
          "field_video:file:field_file_image_title_text" : {
            "table" : "search_api_db_default_node_index_text_1",
            "type" : "text",
            "boost" : "1.0",
            "column" : "field_video_file_field_file_image_title_text"
          },
          "field_video_auth:file:name" : {
            "table" : "search_api_db_default_node_index_text_1",
            "type" : "text",
            "boost" : "1.0",
            "column" : "field_video_auth_file_name"
          },
          "field_video_auth:file:field_file_image_alt_text" : {
            "table" : "search_api_db_default_node_index_text_1",
            "type" : "text",
            "boost" : "1.0",
            "column" : "field_video_auth_file_field_file_image_alt_text"
          },
          "field_video_auth:file:field_file_image_title_text" : {
            "table" : "search_api_db_default_node_index_text_1",
            "type" : "text",
            "boost" : "1.0",
            "column" : "field_video_auth_file_field_file_image_title_text"
          }
        }
      }
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
