<?php
/**
 * @file
 * stanford_news_extras_importer.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function stanford_news_extras_importer_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_news_taxonomy|node|stanford_news_item|form';
  $field_group->group_name = 'group_s_news_taxonomy';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'stanford_news_item';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Categories',
    'weight' => '14',
    'children' => array(
      0 => 'field_s_news_department',
      1 => 'field_s_news_organization',
      2 => 'field_s_news_research_theme',
      3 => 'field_s_news_school_theme',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Categories',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-s-news-taxonomy field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_s_news_taxonomy|node|stanford_news_item|form'] = $field_group;

  return $export;
}
