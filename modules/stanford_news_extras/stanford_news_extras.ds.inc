<?php
/**
 * @file
 * stanford_news_extras.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function stanford_news_extras_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|stanford_news_item|stanford_news_extras';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'stanford_news_item';
  $ds_layout->view_mode = 'stanford_news_extras';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_s_postcard',
        1 => 'field_s_news_teaser',
        2 => 'field_s_news_date',
        3 => 'field_s_news_byline',
        4 => 'field_s_image_info',
        5 => 'body',
        6 => 'group_s_postcard_image',
        7 => 'group_s_postcard_content',
      ),
    ),
    'fields' => array(
      'group_s_postcard' => 'ds_content',
      'field_s_news_teaser' => 'ds_content',
      'field_s_news_date' => 'ds_content',
      'field_s_news_byline' => 'ds_content',
      'field_s_image_info' => 'ds_content',
      'body' => 'ds_content',
      'group_s_postcard_image' => 'ds_content',
      'group_s_postcard_content' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|stanford_news_item|stanford_news_extras'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function stanford_news_extras_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'stanford_news_extras';
  $ds_view_mode->label = 'News Extras';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['stanford_news_extras'] = $ds_view_mode;

  return $export;
}
