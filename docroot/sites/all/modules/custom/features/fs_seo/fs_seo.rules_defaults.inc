<?php
/**
 * @file
 * fs_seo.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function fs_seo_default_rules_configuration() {
  $items = array();
  $items['rules_publish_to_twitter'] = entity_import('rules_config', '{ "rules_publish_to_twitter" : {
      "LABEL" : "Publish to twitter",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "twitter" ],
      "REQUIRES" : [ "rules", "twitter_actions" ],
      "ON" : { "node_update" : [] },
      "IF" : [
        { "node_is_published" : { "node" : [ "node" ] } },
        { "node_is_of_type" : {
            "node" : [ "node" ],
            "type" : { "value" : { "podcast" : "podcast", "blog" : "blog", "screencast" : "screencast" } }
          }
        }
      ],
      "DO" : [
        { "rules_core_twitter_actions_set_status_action" : { "message" : "[node:title] [node:url]", "sender" : [ "node:author" ] } }
      ]
    }
  }');
  return $items;
}
