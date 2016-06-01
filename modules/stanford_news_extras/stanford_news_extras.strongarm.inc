<?php
/**
 * @file
 * stanford_news_extras.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function stanford_news_extras_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'stanford_news_banner';
  $strongarm->value = 6890;
  $export['stanford_news_banner'] = $strongarm;

  return $export;
}
