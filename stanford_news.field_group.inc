<?php
/**
 * @file
 * stanford_news.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function stanford_news_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_news_imagemeta|node|news_item|default';
  $field_group->group_name = 'group_s_news_imagemeta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news_item';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Image Meta',
    'weight' => '0',
    'children' => array(
      0 => 'field_s_news_image',
      1 => 'field_s_news_imagecredit',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Image Meta',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'image-info',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_news_imagemeta|node|news_item|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_s_news_imagemeta|node|news_item|form';
  $field_group->group_name = 'group_s_news_imagemeta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'news_item';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '2',
    'children' => array(
      0 => 'field_s_news_image',
      1 => 'field_s_news_imagecredit',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'image-info',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_s_news_imagemeta|node|news_item|form'] = $field_group;

  return $export;
}
