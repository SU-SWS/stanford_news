<?php
/**
 * @file
 * stanford_news_extras.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function stanford_news_extras_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_new_byline_descriptor|node|stanford_news_item|full';
  $field_group->group_name = 'group_s_new_byline_descriptor';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_s_news_teaser';
  $field_group->data = array(
    'label' => 'Descriptor',
    'weight' => '1',
    'children' => array(
      0 => 'field_s_news_byline',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Descriptor',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'descriptor',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_new_byline_descriptor|node|stanford_news_item|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_news_teaser_byline|node|stanford_news_item|form';
  $field_group->group_name = 'group_s_news_teaser_byline';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Teaser/Byline',
    'weight' => '13',
    'children' => array(
      0 => 'field_s_news_byline',
      1 => 'field_s_news_teaser',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-s-news-teaser-byline field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_s_news_teaser_byline|node|stanford_news_item|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_news_teaser|node|stanford_news_item|full';
  $field_group->group_name = 'group_s_news_teaser';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_s_postcard_content';
  $field_group->data = array(
    'label' => 'Teaser',
    'weight' => '23',
    'children' => array(
      0 => 'field_s_news_teaser',
      1 => 'group_s_new_byline_descriptor',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Teaser',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-s-news-teaser field-group-div lead',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_news_teaser|node|stanford_news_item|full'] = $field_group;

  return $export;
}
